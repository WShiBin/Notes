# UUID

>   用于生成UUID(Universally Unique Identifier，通用唯一标识符)的库，一个UUID是一个16字节(128位)的数字，一般通过32个十六进制表示，一个UUID被连字符分成5段，标准的UUID格式为xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx，即形式为8-4-4-4-12的32个字符，其中字母是16进制表示，大小写无关。
>

from:https://github.com/certik/uuid (copy from [util-linux](http://en.wikipedia.org/wiki/Util-linux))

**两种生成uuid的方式**

* 基于随机数生成UUID(优先)
* 基于时间生成UUID

## API
头文件：uuid.h
```c
// uuid结构体
typedef unsigned char uuid_t[16];

/* UUID Variant definitions */ // uuid variant
#define UUID_VARIANT_NCS	0
#define UUID_VARIANT_DCE	1
#define UUID_VARIANT_MICROSOFT	2
#define UUID_VARIANT_OTHER	3

/* UUID Type definitions */
#define UUID_TYPE_DCE_TIME   1 // uuid类型(基于事件生成)
#define UUID_TYPE_DCE_RANDOM 4 // uuid类型(基于随机数生成)

/* clear.c */
void uuid_clear(uuid_t uu); // 清理uuid

/* compare.c */
int uuid_compare(const uuid_t uu1, const uuid_t uu2); // 比较uuid

/* copy.c */
void uuid_copy(uuid_t dst, const uuid_t src); // copy uuid

/* gen_uuid.c */
void uuid_generate(uuid_t out); // 基于随机数或时间生成uuid,优先随机数
void uuid_generate_random(uuid_t out);　// 基于随机数生成uuid
void uuid_generate_time(uuid_t out); // 基于事件生成uuid

/* isnull.c */
int uuid_is_null(const uuid_t uu); // 判断是否为空

/* parse.c */
int uuid_parse(const char *in, uuid_t uu); // 把一个字符串(理论上是36个长度)解析成uuid

/* unparse.c */
void uuid_unparse(const uuid_t uu, char *out); // uuid转成16进制字符(xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx)
void uuid_unparse_lower(const uuid_t uu, char *out); // uuid转成16进制小写字符
void uuid_unparse_upper(const uuid_t uu, char *out); // uuid转成16进制大写字符

/* uuid_time.c */
time_t uuid_time(const uuid_t uu, struct timeval *ret_tv); // 根据uuid获取其中时间
int uuid_type(const uuid_t uu); // 判断uuid的类型
int uuid_variant(const uuid_t uu); // 获取uuid variant(用来标识uuid的格式和编码: wiki:https://en.wikipedia.org/wiki/Universally_unique_identifier#Variants)
```

## 使用

```c
#include <stdio.h>
#include <time.h>

#include "uuid.h"

int main(int argc, char* argv[]) {
    uuid_t uuid;
    char   uuid_str[37] = {0};

    // 1.uuid_generate
    uuid_generate(uuid);           // 生成uuid
    uuid_unparse(uuid, uuid_str);  // uuid转成十六进制字符串(36长度)
    printf("uuid = %s\n", uuid_str);

    // 2.uuid_generate_random
    uuid_generate_random(uuid);    // 生成uuid
    uuid_unparse(uuid, uuid_str);  // uuid转成十六进制字符串(36长度)
    printf("base on random uuid = %s\n", uuid_str);

    // 3.uuid_generate_time
    uuid_generate_time(uuid);      // 生成uuid
    uuid_unparse(uuid, uuid_str);  // uuid转成十六进制字符串(36长度)
    printf("base on time uuid = %s\n", uuid_str);

    // 4. uuid_time, uuid_type, uuid_variant
    struct timeval tv;
    time_t         time = uuid_time(uuid, &tv);
    printf("tv = (%ld, %ld); time = %s", tv.tv_sec, tv.tv_usec, ctime(&time));

    int type = uuid_type(uuid);
    if (type == UUID_TYPE_DCE_TIME) {
        printf("uuid type is : UUID_TYPE_DCE_TIME\n");
    } else if (type == UUID_TYPE_DCE_RANDOM) {
        printf("uuid type is : UUID_TYPE_DCE_RANDOM\n");
    }

    int variant = uuid_variant(uuid);
    if (variant == UUID_VARIANT_NCS) {
        printf("uuid variant is : UUID_VARIANT_NCS\n");
    } else if (variant == UUID_VARIANT_DCE) {
        printf("uuid variant is : UUID_VARIANT_DCE\n");
    } else if (variant == UUID_VARIANT_MICROSOFT) {
        printf("uuid variant is : UUID_VARIANT_MICROSOFT\n");
    } else if (variant == UUID_VARIANT_OTHER) {
        printf("uuid variant is : UUID_VARIANT_OTHER\n");
    }

    // 5.other: uuid_is_null, uuid_unparse_lower, uuid_unparse_upper, uuid_clear
    int ret = uuid_is_null(uuid);
    if (ret) {
        printf("uuid is null\n");
    } else {
        printf("uuid is not null\n");
    }

    uuid_unparse_lower(uuid, uuid_str);  // uuid转成十六进制字符串
    printf("lower uuid = %s\n", uuid_str);
    uuid_unparse_upper(uuid, uuid_str);  // uuid转成十六进制字符串
    printf("upper uuid = %s\n", uuid_str);

    uuid_clear(uuid);
    return 0;
}
```

输出:

```
uuid = dd18aa44-9594-41a2-b80c-d894851508a8
base on random uuid = 71e08c50-47f5-45ef-adad-b1af80e40e98
base on time uuid = e3840b20-1f3d-11eb-b204-6378fb95e6ae

tv = (1604563623, 547984); time = Thu Nov  5 16:07:03 2020
uuid type is : UUID_TYPE_DCE_TIME
uuid variant is : UUID_VARIANT_DCE

uuid is not null
lower uuid = e3840b20-1f3d-11eb-b204-6378fb95e6ae
upper uuid = E3840B20-1F3D-11EB-B204-6378FB95E6AE
```

