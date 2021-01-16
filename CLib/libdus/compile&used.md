# 编译&使用

## 编译

依赖于libexpat(xml解析)

```bash
$ mkdir build
$ cd build
$ cmake ../cmake
$ make
```

## 启动

### 启动bus


```bash
# 启动:内部会调用dbus-daemon
$ dbus-launch
DBUS_SESSION_BUS_ADDRESS=unix:abstract=/tmp/dbus-4PCOjjuzYT,guid=ec6cccc854f5e1c0b85ca0a25ffffe51
DBUS_SESSION_BUS_PID=35201

$ export DBUS_SESSION_BUS_ADDRESS

```
启动脚本:如果DBUS_SESSION_BUS_ADDRESS变量不存在就去启动

```bash
#!/bin/bash
## test for an existing bus daemon, just to be safe
if test -z "$DBUS_SESSION_BUS_ADDRESS"; then
    ## if not found, launch a new one
    eval $(dbus-launch --sh-syntax --exit-with-session)
    echo "D-Bus per-session daemon address is: $DBUS_SESSION_BUS_ADDRESS"
fi
```

### 启动通信的进程

> 其它进程会根据启动bus之后, 提供的dbus地址(DBUS_SESSION_BUS_ADDRESS)来去连接bus 守护进程.

```bash
$ DBUS_SESSION_BUS_ADDRESS=unix:abstract=/tmp/dbus-4PCOjjuzYT ./send_signal
```



### Ubuntu下进程状态

```bash
$ ps -ef | grep dbus
message+  1401     1  0 Jan11 ?        00:04:58 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
gdm       2121  2068  0 Jan11 ?        00:00:00 /usr/bin/dbus-daemon --session --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
gdm       2236  2231  0 Jan11 ?        00:00:00 /usr/bin/dbus-daemon --config-file=/usr/share/defaults/at-spi2/accessibility.conf --nofork --print-address 3
shibin    6163  6121  0 Jan11 ?        00:00:10 /usr/bin/dbus-daemon --session --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
shibin    6199     1  0 Jan11 ?        00:00:06 /usr/bin/dbus-daemon --syslog --fork --print-pid 5 --print-address 7 --config-file /usr/share/fcitx/dbus/daemon.conf
shibin    6203     1  0 Jan11 ?        00:00:00 /usr/bin/fcitx-dbus-watcher unix:abstract=/tmp/dbus-RCxVrw9fyZ,guid=915a6890ce75e2037ac4eae25ffbaa6f 6199
shibin    6278  6273  0 Jan11 ?        00:00:01 /usr/bin/dbus-daemon --config-file=/usr/share/defaults/at-spi2/accessibility.conf --nofork --print-address 3
```