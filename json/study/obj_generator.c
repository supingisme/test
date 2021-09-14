#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <json-c/json.h>

//gcc obj_generator.c -ljson-c

struct latency_node {
    char *ItemName;
    char *DstIpAddr;
    unsigned long int MicroSec;
};


void test_device_latency_m2(const char *objName, int objID, const struct latency_node *ln, int nr_node, 
                            char *json_fmt, const int json_fmt_len)
{
    
    json_object *LatencyJsonObj = json_object_new_object();
    
    json_object_object_add(LatencyJsonObj, "Name", json_object_new_string(objName));
    json_object_object_add(LatencyJsonObj, "ID", json_object_new_int(objID));

    int idx = 0;
    for(idx=0;idx<nr_node;idx++) {

        json_object *subObj = json_object_new_object();
        
        json_object_object_add(subObj, "DstIP", json_object_new_string(ln[idx].DstIpAddr));
        json_object_object_add(subObj, "MicroSec", json_object_new_int(ln[idx].MicroSec));
        
        json_object_object_add(LatencyJsonObj, ln[idx].ItemName, subObj);
        
    }

    strncpy(json_fmt, json_object_to_json_string(LatencyJsonObj), json_fmt_len);
    
}

void test_device_latency()
{
    char jsonfmt1[1024] = {0};
    struct latency_node list1[] = {
        {"CUUP-UPF", "10.170.6.66", 100},
        {"DU-UPF", "10.170.6.66", 100},
        {"DU-UE-1", "10.170.6.66", 100},
        {"DU-UE-2", "10.170.6.67", 101},
        {"DU-UE-3", "10.170.6.67", 101},
    };
    test_device_latency_m2("Latency", 1, list1, 5, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}

struct timerun {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_day;
    int tm_year;
};


int get_process_runtime_json_fmt(const char *objName, int objID, struct timerun *tr,
                                    char *json_fmt, const int json_fmt_len)
{
    
    json_object *RuntimeJsonObj = json_object_new_object();
    
    json_object_object_add(RuntimeJsonObj, "Name", json_object_new_string(objName));
    json_object_object_add(RuntimeJsonObj, "ID", json_object_new_int(objID));
    json_object_object_add(RuntimeJsonObj, "years", json_object_new_int(tr->tm_year));
    json_object_object_add(RuntimeJsonObj, "days", json_object_new_int(tr->tm_day));
    json_object_object_add(RuntimeJsonObj, "hours", json_object_new_int(tr->tm_hour));
    json_object_object_add(RuntimeJsonObj, "minutes", json_object_new_int(tr->tm_min));
    json_object_object_add(RuntimeJsonObj, "seconds", json_object_new_int(tr->tm_sec));
    
    
    strncpy(json_fmt, json_object_to_json_string(RuntimeJsonObj), json_fmt_len);
}

void test_device_runtime()
{
    char jsonfmt1[1024] = {0};
    struct timerun time = { 57,59,23,12,1,  };
    get_process_runtime_json_fmt("Runtime", 1, &time, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}

struct core_occupy {
    int cpuid;
    struct {
        int integer, decimal;
    }occupy;
};

void get_device_cpu_occupy_json_fmt(const char *objName, int objID, 
                            const struct core_occupy *occupy, int nr_core, 
                            char *json_fmt, const int json_fmt_len)
{
    
    json_object *LatencyJsonObj = json_object_new_object();
    
    json_object_object_add(LatencyJsonObj, "Name", json_object_new_string(objName));
    json_object_object_add(LatencyJsonObj, "ID", json_object_new_int(objID));

    int idx = 0;
    for(idx=0;idx<nr_core;idx++) {

        char cpuName[16] = {0};
        char cpuOccupy[16] = {0};
        
        sprintf(cpuName, "CPU%d", occupy[idx].cpuid);
        sprintf(cpuOccupy, "%d.%d%%", occupy[idx].occupy.integer, occupy[idx].occupy.decimal);

        json_object *subObj = json_object_new_object();
        
        json_object_object_add(subObj, "CpuID", json_object_new_int(occupy[idx].cpuid));
        json_object_object_add(subObj, "Utilization", json_object_new_string(cpuOccupy));
        
        json_object_object_add(LatencyJsonObj, cpuName, subObj);
        
    }

    strncpy(json_fmt, json_object_to_json_string(LatencyJsonObj), json_fmt_len);
    
}

void test_device_cpu_occupy()
{
    char jsonfmt1[1024] = {0};
    struct core_occupy occupy[] = {
        {-1, {10,1}},
        {0, {11,2}},
        {1, {12,3}},
        {2, {13,4}},
    };
    get_device_cpu_occupy_json_fmt("CpuOccupy", 1, occupy, 4, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}

struct fs_occupy_info {
   char fs_name[64];   /* name of mounted file system */
   char fs_mnt_dir[128];      /* file system path prefix */
   char fs_type[64];     /* mount type (see mntent.h) */

   unsigned long int totalMB;
   unsigned long int freeMB;

   struct {
        int integer;
        int decimal;
   }occupy;
};

void get_device_fs_occupy_json_fmt(const char *objName, int objID, 
                            const struct fs_occupy_info *occupy, int nr_fs, 
                            char *json_fmt, const int json_fmt_len)
{
    
    json_object *LatencyJsonObj = json_object_new_object();
    
    json_object_object_add(LatencyJsonObj, "Name", json_object_new_string(objName));
    json_object_object_add(LatencyJsonObj, "ID", json_object_new_int(objID));

    int idx = 0;
    for(idx=0;idx<nr_fs;idx++) {

        char fsName[64] = {0};
        char fsOccupy[64] = {0};
        
        sprintf(fsName, "FS%d", idx+1);
        sprintf(fsOccupy, "%d.%d%%", occupy[idx].occupy.integer, occupy[idx].occupy.decimal);

        json_object *subObj = json_object_new_object();
        
        json_object_object_add(subObj, "FsName", json_object_new_string(occupy[idx].fs_name));
        json_object_object_add(subObj, "FsType", json_object_new_string(occupy[idx].fs_type));
        
        json_object_object_add(subObj, "TotalMB", json_object_new_int(occupy[idx].totalMB));

        json_object_object_add(subObj, "Utilization", json_object_new_string(fsOccupy));
        
        json_object_object_add(LatencyJsonObj, fsName, subObj);
        
    }

    strncpy(json_fmt, json_object_to_json_string(LatencyJsonObj), json_fmt_len);
    
}

void test_device_fs_occupy()
{
    char jsonfmt1[1024] = {0};
    struct fs_occupy_info occupy[] = {
        {"centos-home", "/home",            "rootfs",   10240, 1024, {10, 96}},
        {"/dev/vda1",   "/boot",            "ext2",     10241, 1025, {11, 97}},
        {"/dev/vdb",    "/work",            "ext3",     10242, 1026, {12, 98}},
        {"tmpfs",       "/run/user/1002",   "ext4",     10243, 1027, {13, 99}},
    };
    get_device_fs_occupy_json_fmt("FsOccupy", 1, occupy, 4, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}


/**
 *  struct ram_occupy - RAM使用情况结构体
 *  
 *  具体参数见参数说明
 */
struct ram_occupy {
    unsigned long totalRamMemMb;    /* 总的可用主内存大小 */
    unsigned long freeRamMemMb;     /* 可用的内存大小 */
    unsigned long totalSwapMb;      /* 总交换空间大小 */
    unsigned long freeSwapMb;       /* 可用的交换空间大小 */
    struct {
        int integer;    //使用率的整数部分
        int decimal;    //使用率的小数部分
    }occupyRam, occupySwap;         /* 使用率；按   80.23 % 记 */
};


int get_ram_occupy_json_fmt(const char *objName, int objID, struct ram_occupy *ro,
                                    char *json_fmt, const int json_fmt_len)
{
    
    json_object *RuntimeJsonObj = json_object_new_object();
    
    char RamOccupy[64] = {0};
    char SwapOccupy[64] = {0};
    

    sprintf(RamOccupy, "%d.%d%%", ro->occupyRam.integer, ro->occupyRam.decimal);
    sprintf(SwapOccupy, "%d.%d%%", ro->occupySwap.integer, ro->occupySwap.decimal);

    
    json_object_object_add(RuntimeJsonObj, "Name", json_object_new_string(objName));
    json_object_object_add(RuntimeJsonObj, "ID", json_object_new_int(objID));
    json_object_object_add(RuntimeJsonObj, "TotalRamMemMb", json_object_new_int(ro->totalRamMemMb));
    json_object_object_add(RuntimeJsonObj, "FreeRamMemMb", json_object_new_int(ro->freeRamMemMb));
    json_object_object_add(RuntimeJsonObj, "RamMemUtilization", json_object_new_string(RamOccupy));
    json_object_object_add(RuntimeJsonObj, "TotalSwapMemMb", json_object_new_int(ro->totalSwapMb));
    json_object_object_add(RuntimeJsonObj, "FreeSwapMemMb", json_object_new_int(ro->freeSwapMb));
    json_object_object_add(RuntimeJsonObj, "SwapUtilization", json_object_new_string(SwapOccupy));
    json_object_object_add(RuntimeJsonObj, "Name", json_object_new_string(objName));
    
    
    strncpy(json_fmt, json_object_to_json_string(RuntimeJsonObj), json_fmt_len);
}

void test_ram_occupy()
{
    char jsonfmt1[1024] = {0};
    struct ram_occupy occupy = { 
        20480, 2048, 10240, 1024, {11,11}, {12,12}
    };
    get_ram_occupy_json_fmt("RamOccupy", 1, &occupy, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}



struct ifinfo {
    unsigned int if_idx;    //接口索引号
    char if_name[32];       //接口名 如：eth0

    int if_flag;
#define IFSTAT_UP           0x0001  /* 接口状态为 up */
#define IFSTAT_BROADCAST    0x0002  /* 广播地址可用 */
#define IFSTAT_LOOPBACK     0x0004  /* 该网口是回环口 */
#define IFSTAT_POINTOPOINT  0x0010  /* 点对点连接 */
#define IFSTAT_MULTICAST    0x0020  /* 支持多播 */

    char if_ipv4[16];       //接口IPv4地址
    struct {
        char if_ethmac[64];         //MAC地址
        unsigned int if_ethspeed;   //速率 Mbps
    }if_eth;
};


void get_net_interface_json_fmt(const char *objName, int objID, 
                            const struct ifinfo *netif, int nr_if, 
                            char *json_fmt, const int json_fmt_len)
{
    
    json_object *LatencyJsonObj = json_object_new_object();
    
    json_object_object_add(LatencyJsonObj, "Name", json_object_new_string(objName));
    json_object_object_add(LatencyJsonObj, "ID", json_object_new_int(objID));

    int idx = 0;
    for(idx=0;idx<nr_if;idx++) {

        char ifName[64] = {0};
        
        sprintf(ifName, "IF%d", netif[idx].if_idx);

        json_object *subObj = json_object_new_object();
        
        json_object_object_add(subObj, "IfName", json_object_new_string(netif[idx].if_name));
        json_object_object_add(subObj, "IfAddr", json_object_new_string(netif[idx].if_ipv4));
        
        json_object_object_add(subObj, "IfMac", json_object_new_string(netif[idx].if_eth.if_ethmac));
        json_object_object_add(subObj, "IfSpeedMbps", json_object_new_int(netif[idx].if_eth.if_ethspeed));
        
        json_object_object_add(LatencyJsonObj, ifName, subObj);
        
    }

    strncpy(json_fmt, json_object_to_json_string(LatencyJsonObj), json_fmt_len);
    
}

void test_device_net_interface()
{
    char jsonfmt1[1024] = {0};
    struct ifinfo ifs[] = {
        {0, "em1", IFSTAT_UP, "10.170.6.66", {"28:6e:d4:88:c7:9a", 1000}},
        {1, "em2", IFSTAT_UP, "10.170.6.67", {"28:6e:d4:88:c7:9b", 1001}},
        {2, "em3", IFSTAT_UP, "10.170.6.68", {"28:6e:d4:88:c7:9c", 1002}},
        {3, "em4", IFSTAT_UP, "10.170.6.69", {"28:6e:d4:88:c7:9d", 1003}},
    };
    get_net_interface_json_fmt("IfInfo", 1, ifs, 4, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}



int main()
{
//    test_device_latency();
//    test_device_runtime();
//    test_device_cpu_occupy();
//    test_device_fs_occupy();
//    test_ram_occupy();
    test_device_net_interface();
    
}


