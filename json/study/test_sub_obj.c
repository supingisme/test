#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <json-c/json.h>

void test_basic()
{
    json_object *obj1 = json_object_new_object();
    json_object *obj2 = json_object_new_object();
    json_object *obj3 = json_object_new_object();
    
    json_object_object_add(obj1, "obj1int", json_object_new_int(1));
    json_object_object_add(obj2, "obj2int", json_object_new_int(2));
    json_object_object_add(obj3, "obj3int", json_object_new_int(3));
    
    json_object_object_add(obj2, "obj3", obj3);
    json_object_object_add(obj1, "obj2", obj2);
    
    printf("\tResult:%s\r\n", json_object_to_json_string(obj1));
}

void test_device_latency()
{
    const struct latency {
        char *name;
        struct {
            char *dst_name;
            char *dst_ip;
        }dstinfo;
        struct {
            char *name;
            unsigned long int microseconds;
        }latencyInfo;
    } latency_data[] = {
        {"CUUP-UPF", {"DstIp", "10.170.6.66"}, {"Latency", 996}},
        {"DU-UPF",   {"DstIp", "10.170.6.67"}, {"Latency", 997}},
        {"UE-UPF:1",   {"DstIp", "10.170.6.68"}, {"Latency", 998}},
        {"UE-UPF:2",   {"DstIp", "10.170.6.69"}, {"Latency", 999}}, //这里应该支持多UE
        {"UE-UPF:3",   {"DstIp", "10.170.6.70"}, {"Latency", 1000}}, //这里应该支持多UE
        {NULL, {NULL, NULL}, {NULL, 0}},
    };
//        { 
//            "CUUP-UPF": { "DstIp": "10.170.6.66", "Latency": 996 }, 
//            "DU-UPF": { "DstIp": "10.170.6.67", "Latency": 997 }, 
//            "UE-UPF:1": { "DstIp": "10.170.6.68", "Latency": 998 }, 
//            "UE-UPF:2": { "DstIp": "10.170.6.69", "Latency": 999 }, 
//            "UE-UPF:3": { "DstIp": "10.170.6.70", "Latency": 1000 } 
//        }

    
    json_object *LatencyJsonObj = json_object_new_object();

    int idx = 0;
    while(latency_data[idx].name) {

        json_object *subObj = json_object_new_object();
        
        json_object_object_add(subObj, latency_data[idx].dstinfo.dst_name, 
                                        json_object_new_string(latency_data[idx].dstinfo.dst_ip));
        json_object_object_add(subObj, latency_data[idx].latencyInfo.name, 
                                        json_object_new_int(latency_data[idx].latencyInfo.microseconds));
        
        json_object_object_add(LatencyJsonObj, latency_data[idx].name, subObj);
        
        idx++;
    }

    printf("\tResult:%s\r\n", json_object_to_json_string(LatencyJsonObj));
}

struct latency_node {
    char *LatencyName;
    char *DstIpAddr;
    unsigned long int microseconds;
};

void test_device_latency_m2(const struct latency_node *ln, unsigned int nr_node, char *json_fmt, const int json_fmt_len)
{
    
    json_object *LatencyJsonObj = json_object_new_object();

    int idx = 0;
    for(idx=0;idx<nr_node;idx++) {

        json_object *subObj = json_object_new_object();
        
        json_object_object_add(subObj, "DstIP", json_object_new_string(ln[idx].DstIpAddr));
        json_object_object_add(subObj, "MicroSec", json_object_new_int(ln[idx].microseconds));
        
        json_object_object_add(LatencyJsonObj, ln[idx].LatencyName, subObj);
        
    }

    strncpy(json_fmt, json_object_to_json_string(LatencyJsonObj), json_fmt_len);
    
}


int main()
{
//    test_basic();
//
//    test_device_latency();

    char jsonfmt1[1024] = {0};
    struct latency_node list1[] = {
        {"CUUP-UPF", "10.170.6.66", 100},
        {"DU-UPF", "10.170.6.66", 100},
        {"DU-UE-1", "10.170.6.66", 100},
        {"DU-UE-2", "10.170.6.67", 101},
        {"DU-UE-3", "10.170.6.67", 101},
    };
    test_device_latency_m2(list1, 5, jsonfmt1, 1024);
    printf("%s\n", jsonfmt1);
}

