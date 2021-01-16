# DBus命令工具使用

## 命令工具
* dbus-daemon(1)
* dbus-send(1)
* dbus-monitor(1)
* dbus-launch(1)
* dbus-uuidgen(1)

## dbus-daemon

Message bus daemon

message bus地址:

* System bus: 环境变量DBUS_SYSTEM_BUS_ADDRESS, 编译时指定默认地址DBUS_SYSTEM_BUS_DEFAULT_ADDRESS
* Session bus: DBUS_SESSION_BUS_ADDRESS

```bash
# start system bus
# 编译时可通过变量DBUS_SYSTEM_BUS_DEFAULT_ADDRESS指定变量地址
$ DBUS_VERBOSE=1 dbus-daemon --system --print-address
# start session bus
# 运行后生成变量DBUS_SESSION_BUS_ADDRESS
$ DBUS_VERBOSE=1 dbus-daemon --session --print-address
```

## dbus-send

Send a message to a message bus

```bash
# send signal
$ dbus-send --type=signal /  org.signal.poweroff.test_signal string:"hello"

# send method call
$ dbus-send --dest=org.freedesktop.ExampleName               \
            /org/freedesktop/sample/object/name              \
            org.freedesktop.ExampleInterface.ExampleMethod   \
            int32:47 string:'hello world' double:65.32       \
            array:string:"1st item","next item","last item"  \
            dict:string:int32:"one",1,"two",2,"three",3      \
            variant:int32:-8                                 \
            objpath:/org/freedesktop/sample/object/name
```

## dbus-monitor

debug probe to print message bus messages

```bash
$ dbus-monitor "type='signal',sender='org.gnome.TypingMonitor',interface='org.gnome.TypingMonitor'"
```

## dbus-launch

Utility to start a message bus from a shell script

```bash
$ dbus-launch --sh-syntax
```

启动脚本
```bash
## test for an existing bus daemon, just to be safe
if test -z "$DBUS_SESSION_BUS_ADDRESS" ; then
    ## if not found, launch a new one
    eval `dbus-launch --sh-syntax`
    echo "D-Bus per-session daemon address is: $DBUS_SESSION_BUS_ADDRESS"
fi
```

## dbus-uuidgen

Utility to generate UUIDs

```bash
# it just prints a new uuid
$ dbus-uuidgen
ebb40ad49f9d4d8f44faa3bc5fffdc27

# prints the machine UUID by default
$ dbus-uuidgen --get
5b86dc18cce752c5404d2f0a5ffd1885

$ dbus-uuidgen --ensure=/usr/local/var/lib/dbus/machine-id
```