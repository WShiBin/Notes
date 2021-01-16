## D-Bus中的概念

### 地址

连接建立有server和client，对于bus daemon，应用就是client，daemon是server。 一个D-Bus的地址是指server用于监听，client用于连接的地方，例如unix:path=/tmp/abcedf标识server将在路径/tmp/abcedf的UNIX domain socket监听。 地址可以是指定的TCP/IP socket或者其他在或者将在D-Bus协议中定义的传输方式。 如果使用bus daemon，libdbus将通过读取环境变量自动获取session bus damon的地址，通过检查一个指定的UNIX domain socket路径获取system bus的地址。如果使用D-bus，但不是daemon，需要定义那个应用是server，那个是client，并定义一套机制是他们认可server的地址，这不是通常的做法。

### Bus Names总线名字

当一个应用连接到bus daemon，daemon立即会分配一个名字给这个连接，称为unique connection name， 这个唯一标识的名字以冒号：开头，例如:34-907，这个名字在daemon的整个生命周期是唯一的。 但是这种名字总是临时分配，无法确定的，也难以记忆，因此应用可以要求有另外一个名字well-known name 来对应这个唯一标识，就像我们使用域名来对应IP地址一样。 例如可以使用com.mycompany来映射:34-907。应用程序可能会要求拥有额外的周知名字（well-known name）。 例如，你可以写一个规范来定义一个名字叫做 com.mycompany.TextEditor。 应用程序就可以发送消息到这个总线名字，对象，和接口以执行方法调用。 当一个应用结束或者崩溃是，OS kernel会关闭它的总线连接。总线发送notification消息告诉其他应用，这个应用的名字已经失去他的owner。 当检测到这类notification时，应用可以知道其他应用的生命周期。这种方式也可用于只有一个实例的应用，即不开启同样的两个应用的情况。

### 原生对象和对象路径

所有使用D-BUS的应用程序都包含一些对象, 当经由一个D-BUS连接受到一条消息时，该消息是被发往一个对象而不是整个应用程序。 在开发中程序框架定义着这样的对象，例如JAVA，GObject，QObject等等，在D-Bus中成为native object。 对于底层的D-Bus协议，即libdbus API，并不理会这些native object，它们使用的是一个叫做object path的概念。 通过object path，高层编程可以为对象实例进行命名，并允许远程应用引用它们。 这些名字看起来像是文件系统路径，易读的路径名是受鼓励的做法，但也允许使用诸如“/com/mycompany/c5yo817y0c1y1c5b”等，只要它可以为你的应用程序所用。 Namespacing的对象路径以开发者所有的域名开始（如 /org/kde）以避免系统不同代码模块互相干扰。 简单地说：一个应用创建对象实例进行D-Bus的通信，这些对象实例都有一个名字，命名方式类似于路径， 例如/com/mycompany，这个名字在全局（session或者system）是唯一的，用于消息的路由。

### Proxies代理

代理对象用来表示其他远程的remote object。 当我们触发了proxy对象的method时，将会在D-Bus上发送一个method_call的消息，并等待答复，根据答复返回。使用非常方便，就像调用一个本地的对象。

### 接口Interface

每一个对象支持一个或者多个接口，接口是一组方法和信号，接口定义一个对象实体的类型。 D-Bus对接口的命名方式，类似org.freedesktop.Introspectable。开发人员通常将使用编程语言类的的名字作为接口名字。

### 方法和信号Methods and Signals

每一个对象有两类成员：方法和信号。方法就是JAVA中同样概念，方法是一段函数代码，带有输入和输出。信号是广播给所有兴趣的其他实体，信号可以带有数据payload。 在 D-BUS 中有四种类型的消息：**方法调用**（method calls）、**方法返回**（method returns）、**信号**（signals）和**错误**（errors）。 要执行D-BUS对象的方法，您需要向对象发送一个方法调用消息。 它将完成一些处理（就是执行了对象中的Method，Method是可以带有输入参数的。）并返回，返回消息或者错误消息。 信号的不同之处在于它们不返回任何内容：既没有“信号返回”消息，也没有任何类型的错误消息。
