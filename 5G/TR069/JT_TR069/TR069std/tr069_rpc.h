/**
 *  TR-069
 *  CPE WAN Management Protocol
 *  Issue: 1 Amendment 5
 *  Issue Date: November 2013
 *  CWMP Version: 1.4
 *  Wrote: Rong Tao
 */

#ifndef __TR069_RPC_H
#define __TR069_RPC_H 1

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define TODO(...) 
/**
 *  Table 12 – Data types
 */
typedef unsigned int    unsignedInt;
typedef int             boolean;
typedef time_t	        dateTime;
typedef char            base64; //8
typedef int             anySimpleType;TODO("需要进一步")

static const char *TR069_CPE_ACS_RPC_FUNC_NAME[] = {
//Array of strings containing the names of each of the RPC methods the recipient supports. The list of methods returned by an ACS MUST always include “Inform”.
//For example, a CPE implementing only the baseline methods defined in this version of the specification would return the following list when requested by an ACS:
    "GetRPCMethods"
    "SetParameterValues"
    "GetParameterValues"
    "GetParameterNames"
    "SetParameterAttributes"
    "GetParameterAttributes"
    "AddObject"
    "DeleteObject"
    "Reboot"
    "Download"
//As another example, an ACS implementing only the baseline methods defined in this version of the specification would return the following list when requested by a CPE:
    "Inform"
    "GetRPCMethods"
    "TransferComplete"
};

/* CPE Methods ************************************************************/
/**
 *  Table 17 – ParameterValueStruct definition
 */
typedef struct ParameterValueStruct_s {
    char Name[256];
    anySimpleType Value;
}ParameterValueStruct;


/**
 *  Table 15 – SetParameterValues arguments
 */
typedef struct SetParameterValues_s {
    ParameterValueStruct *ParameterList;
    char ParameterKey[32];
}SetParameterValues;

/**
 *  Table 16 – SetParameterValuesResponse arguments
 */
typedef struct SetParameterValuesResponse_s {
    int Status[2];
//    A successful response to this method returns an integer enumeration defined as follows:
//    0 = All Parameter changes have been validated and applied.
//    1 = All Parameter changes have been validated and committed, but some or all are not yet applied (for example, if a reboot is required before the new values are applied).
}SetParameterValuesResponse;



/**
 *  Table 18 – GetParameterValues arguments
 */
typedef struct GetParameterValues_s {
    char *ParameterNames[256];
    ParameterValueStruct *ParameterList;
}GetParameterValues;



/**
 *  Table 20 – GetParameterNames arguments
 */
typedef struct GetParameterNames_s {
    char ParameterPath[256];
    boolean NextLevel;  //If false, the response MUST contain the Parameter or Object whose name exactly matches the ParameterPath argument, plus all Parameters and Objects that are descendents of the Object given by the ParameterPath argument, if any (all levels below the specified Object in the Object hierarchy). For example, if ParameterPath were “InternetGatewayDevice.LANDevice.1.Hosts.”, the response would include the following (if there were a single instance of Host with Instance Number “1”):
                        //InternetGatewayDevice.LANDevice.1.Hosts. InternetGatewayDevice.LANDevice.1.Hosts.HostNumberOfEntries InternetGatewayDevice.LANDevice.1.Hosts.Host. InternetGatewayDevice.LANDevice.1.Hosts.Host.1. InternetGatewayDevice.LANDevice.1.Hosts.Host.1.IPAddress InternetGatewayDevice.LANDevice.1.Hosts.Host.1.AddressSource InternetGatewayDevice.LANDevice.1.Hosts.Host.1.LeaseTimeRemaining InternetGatewayDevice.LANDevice.1.Hosts.Host.1.MACAddress InternetGatewayDevice.LANDevice.1.Hosts.Host.1.HostName InternetGatewayDevice.LANDevice.1.Hosts.Host.1.InterfaceType InternetGatewayDevice.LANDevice.1.Hosts.Host.1.Active
                        //If true, the response MUST contain all Parameters and Objects that are next-level children of the Object given by the ParameterPath argument, if any. For example, if ParameterPath were “InternetGatewayDevice.LANDevice.1.Hosts.”, the response would include the following:
                        //InternetGatewayDevice.LANDevice.1.Hosts.HostNumberOfEntries InternetGatewayDevice.LANDevice.1.Hosts.Host.
                        //Or, if ParameterPath were empty, with NextLevel equal true, the response would list only “InternetGatewayDevice.” (if the CPE is an Internet Gateway Device).
    
}GetParameterNames;


/**
 *  Table 22 – ParameterInfoStruct definition
 */
typedef struct ParameterInfoStruct_s {
    char Name[256];
    boolean Writable;
}ParameterInfoStruct;


/**
 *  Table 21 – GetParameterNamesResponse arguments
 */
typedef struct GetParameterNamesResponse_s {
    ParameterInfoStruct *ParameterList;
}GetParameterNamesResponse;


/**
 *  Table 25 – SetParameterAttributesStruct definition
 */
typedef struct SetParameterAttributesStruct_s {
    char Name[256];
    boolean NotificationChange;//If true, the value of Notification replaces the current notification setting for this Parameter or group of Parameters. If false, no change is made to the notification setting.
    int Notification[7];//Indicates whether (and how) the CPE will notify the ACS when the specified Parameter(s) change in value. The following values are defined:
                        //0 = Notification off. The CPE need not inform theACS of a change to the specified Parameter(s).
                        //1 = Passive notification. Whenever the specified Parameter value changes, the CPE MUST include the new value in the ParameterList in the Inform message that is sent the next time a Session is established to the ACS.
                        //2 = Active notification. Whenever the specified Parameter value changes, the CPE MUST initiate a Session to the ACS, and include the new value in the ParameterList in the associated Inform message.
                        //3 = Passive lightweight notification. Whenever the specified Parameter value changes, the CPE MUST include the new value in the ParameterList in the next Lightweight Notification message that is sent.
                        //4 = Passive notification with passive lightweight notification. This combines the requirements of the values 1 (Passive notification) and 3 (Passive lightweight notification). The two mechanisms operate independently.
                        //5 = Active lightweight notification. Whenever the specified Parameter value changes, the CPE MUST include the new value in the ParameterList in the associated Lightweight Notification message and send that message.
                        //6 = Passive notification with active lightweight notification. This combines the requirements of the values 1 (Passive notification) and 5 (Active lightweight notification). The two mechanisms operate independently.
    boolean AccessListChange;
    char *AccessList[64];
}SetParameterAttributesStruct;


/**
 *  Table 23 – SetParameterAttributes arguments
 */
typedef struct SetParameterAttributes_s {
    SetParameterAttributesStruct *ParameterList;
}SetParameterAttributes;

/**
 *  Table 24 – SetParameterAttributesResponse arguments
 */
typedef struct SetParameterAttributesResponse_s {
    //void -;
}SetParameterAttributesResponse;



/**
 *  Table 26 – GetParameterAttributes arguments
 */
typedef struct GetParameterAttributes_s {
    char *ParameterNames[256];
}GetParameterAttributes;


/**
 *  Table 28 – ParameterAttributeStruct definition
 */
typedef struct ParameterAttributeStruct_s {
    char Name[256];
    int Notification[7];    //Indicates whether (and how) the CPE will notify the ACS when the specified Parameter(s) change in value. The following values are defined:
                            //0 = Notification off. The CPE need not inform the ACS of a change to the specified Parameter(s).
                            //1 = Passive notification. Whenever the specified Parameter value changes, the CPE MUST include the new value in the ParameterList in the Inform message that is sent the next time a Session is established to the ACS.
                            //2 = Active notification. Whenever the specified Parameter value changes, the CPE MUST initiate a Session to the ACS, and include the new value in the ParameterList in the associated Inform message.
                            //3 = Passive lightweight notification. Whenever the specified Parameter value changes, the CPE MUST include the new value in the ParameterList in the next Lightweight Notification message that is sent.
                            //4 = Passive notification with passive lightweight notification. This combines the requirements of the values 1 (Passive notification) and 3 (Passive lightweight notification). The two mechanisms operate independently.
                            //5 = Active lightweight notification. Whenever the specified parameter value changes, the CPE MUST include the new value in the ParameterList in the associated Lightweight Notification message.
                            //6 = Passive notification with active lightweight notification. This combines the requirements of the values 1 (Passive notification) and 5 (Active lightweight notification). The two mechanisms operate independently.
    char *AccessList[64];
}ParameterAttributeStruct;

/**
 *  Table 27 – GetParameterAttributesResponse arguments
 */
typedef struct GetParameterAttributesResponse_s {
    ParameterAttributeStruct *ParameterList;
}GetParameterAttributesResponse;


/**
 *  Table 29 – AddObject arguments
 */ 
typedef struct AddObject_s {
    char ObjectName[256];
    char ParameterKey[256];
}AddObject;

/**
 *  Table 30 – AddObjectResponse arguments
 */
typedef struct AddObjectResponse_s {
    unsignedInt InstanceNumber[1];
    int Status[2];  //A successful response to this method returns an integer enumeration defined as follows:
                    //0 = The Object has been created.
                    //1 = The Object creation has been validated and committed, but not yet applied (for example, if a reboot is required before the new Object can be applied).
}AddObjectResponse;


/**
 *  Table 31 – DeleteObject arguments
 */
typedef struct DeleteObject_s {
    char ObjectName[256];
    char ParameterKey[256];
}DeleteObject;


/**
 *  Table 32 – DeleteObjectResponse arguments
 */
typedef struct DeleteObjectResponse_s {
    int Status[2];  //A successful response to this method returns an integer enumeration defined as follows:
                    //0 = The Object has been deleted.
                    //1 = The Object deletion has been validated and committed, but not yet applied (for example, if a reboot is required before the Object can be deleted).
}DeleteObjectResponse;



/**
 *  Table 33 – Download arguments
 */
typedef struct Download_s {
    char CommandKey[32];
    char FileType[64];  //An integer followed by a space followed by the file type description. Only the following values are currently defined for the FileType argument:
                        //"1 Firmware Upgrade Image"
                        //"2 Web Content"
                        //“3 Vendor Configuration File”
                        //“4 Tone File” (see [25] Appendix B)
                        //“5 Ringer File” (see [25] Appendix B)
                        //The following format is defined to allow the unique definition of vendor-specific file types:
                        //"X <VENDOR> <Vendor-specific identifier>"
    char URL[256];
    char Username[256];
    char Password[256];
    unsignedInt FileSize;
    char TargetFileName[256];
    unsignedInt DelaySeconds;
    
    char SuccessURL[256];
    char FailureURL[256];
}Download;



/**
 *  Table 34 – DownloadResponse arguments
 */
typedef struct DownloadResponse_s {
    int Status[2];  //A successful response to this method returns an integer enumeration defined as follows:
                    //0 = Download has completed and been applied.
                    //1 = Download has not yet been completed and applied (for example, if the CPE needs to reboot itself before it can perform the file download, or if the CPE needs to reboot itself before it can apply the downloaded file).
                    //If the value of this argument is non-zero, the CPE MUST subsequently call the TransferComplete method to indicate the completion status of this download (either successful or unsuccessful) either later in the same Session or in a subsequent Session.
    dateTime StartTime;
    dateTime CompleteTime;
}DownloadResponse;


/**
 *  Table 35 – Reboot arguments
 */
typedef struct Reboot_s {
    char CommandKey[32];
}Reboot;

/**
 *  Table 36 – RebootResponse arguments
 */
typedef struct RebootResponse_s {
    //void -;
}RebootResponse;



/* ACS Methods ************************************************************/

/**
 *  Table 39 – DeviceIdStruct definition
 */
typedef struct DeviceIdStruct_s {
    char Manufacturer[64];
    char OUI[6];
    char ProductClass[64];
    char SerialNumber[64];
}DeviceIdStruct;


/**
 *  Table 40 – EventStruct definition
 */
typedef struct EventStruct_s {
    char EventCode[64];
    char CommandKey[64];
}EventStruct;


/**
 *  Table 37 – Inform arguments
 */
typedef struct Inform_s {
    DeviceIdStruct DeviceId;
    EventStruct Event[64];
    unsignedInt MaxEnvelopes;
    dateTime CurrentTime;
    unsignedInt RetryCount;
    ParameterValueStruct *ParameterList;
}Inform;



/**
 *  Table 38 – InformResponse arguments
 */
typedef struct InformResponse_s {
    unsignedInt MaxEnvelopes;
}InformResponse;


/**
 *  Table 43 – FaultStruct definition
 */
typedef struct FaultStruct_s {
    unsignedInt FaultCode;
    char FaultString[256];
}__attribute((packed)) FaultStruct;

/**
 *  Table 41 – TransferComplete arguments
 */
typedef struct TransferComplete_s {
    char CommandKey[32];
    FaultStruct FaultStruct;
    dateTime StartTime;
    dateTime CompleteTime;
}TransferComplete;

/**
 *  Table 42 – TransferCompleteResponse arguments
 */
typedef struct TransferCompleteResponse_s {
    //void -;
}TransferCompleteResponse;



/**
 *  Table 44 – AutonomousTransferComplete arguments
 */
typedef struct AutonomousTransferComplete_s {
    char AnnounceURL[1024];
    char TransferURL[1024];
    boolean IsDownload;
    char FileType[64];  //"1 Firmware Upgrade Image" (download only)
                        //"2 Web Content" (download only)
                        //“3 Vendor Configuration File” (download or upload) [DEPRECATED for upload]
                        //“4 Vendor Log File” (upload only) [DEPRECATED]
                        //“4 Tone File” (download only; see [25] Appendix B)
                        //“5 Ringer File” (download only; see [25] Appendix B)
                        //“6 Vendor Configuration File <i>” (upload only)
                        //“7 Vendor Log File <i>” (upload only)
    unsignedInt FileSize;
    char TargetFileName[256];
    FaultStruct FaultStruct;
    dateTime StartTime;
    dateTime CompleteTime;
}AutonomousTransferComplete;

/**
 *  Table 45 – AutonomousTransferCompleteResponse arguments
 */
typedef struct AutonomousTransferCompleteResponse_s {
    //void-;
}AutonomousTransferCompleteResponse;




/**
 *  Table 46 – GetQueuedTransfers arguments
 */
typedef struct GetQueuedTransfers_s {
    //void-;
}GetQueuedTransfers;

/** 
 *  Table 48 – QueuedTransferStruct definition
 */
typedef struct QueuedTransferStruct_s {
    char CommandKey[32];
    int State[3];   //The current state of the transfer. Defined values are:
                    //1 = Not yet started
                    //2 = In progress
                    //3 = Completed, finishing cleanup
                    //All other values are reserved.
}QueuedTransferStruct;

/**
 *  Table 47 – GetQueuedTransfersResponse arguments
 */
typedef struct GetQueuedTransfersResponse_s {
    QueuedTransferStruct TransferList[16];
}GetQueuedTransfersResponse;

/**
 *  Table 49 – ScheduleInform arguments
 */
typedef struct ScheduleInform_s {
    unsignedInt DelaySeconds;
    char CommandKey[32];
}ScheduleInform;

/**
 *  Table 50 – ScheduleInformResponse arguments
 */
typedef struct ScheduleInformResponse_s {
    //void -;
}ScheduleInformResponse;


/**
 *  Table 51 – SetVouchers arguments
 */
typedef struct SetVouchers_s {
    base64 *VoucherList;
}SetVouchers;


/** 
 *  Table 52 – SetVouchersResponse arguments
 */
typedef struct SetVouchersResponse_s {
    //void-;
}SetVouchersResponse;


/**
 *  Table 53 – GetOptions arguments
 */
typedef struct GetOptions_s {
    char OptionName[64];
}GetOptions;


/**
 *  Table 55 – OptionStruct definition
 */
typedef struct OptionStruct_s {
    char OptionName[64];
    unsignedInt VoucherSN;
    unsignedInt State;  //A number formed by two bits, defined as follows:
                        //Bit 0 (LSB):
                        //0 = Option is currently disabled
                        //1 = Option is currently enabled
                        //Bit 1:
                        //0 = Option has not been setup
                        //1 = Option has been setup
    int Mode[3];    //This element specifies whether the designated Option is enabled or disabled; and if enabled, whether or not an expiration has been specified. The defined values are:
                    //0 = Disabled
                    //1 = Enabled with expiration
                    //2 = Enabled without expiration
    dateTime StartDate;
    dateTime ExpirationDate;
    boolean IsTransferable;
}OptionStruct;


/**
 *  Table 54 – GetOptionsResponse arguments
 */
typedef struct GetOptionsResponse_s {
    OptionStruct *OptionList;
}GetOptionsResponse;




/**
 *  Table 56 – Upload arguments
 */
typedef struct Upload_s {
    char CommandKey[32];
    char FileType[64];  //An integer followed by a space followed by the file type description. Only the following values are currently defined for the FileType argument:
                        //“1 Vendor Configuration File” [DEPRECATED]
                        //“2 Vendor Log File” [DEPRECATED]
                        //“3 Vendor Configuration File <i>”
                        //“4 Vendor Log File <i>”
                        //For “3 Vendor Configuration File <i>”, <i> is replaced by the Instance Number from the Vendor Config File object as defined in the appropriate Root Data Model. The CPE uploads the file that corresponds to that entry in the vendor config file table.
                        //For “4 Vendor Log File <i>”, <i> is replaced by the Instance Number from the Vendor Log File object as defined in the appropriate Root Data Model. The CPE uploads the file that corresponds to that entry in the vendor log file table.
                        //The following format is defined to allow the unique definition of vendor-specific file types:
                        //"X <VENDOR> <Vendor-specific identifier>"
    char URL[256];
    char Username[256];
    char Password[256];
    unsignedInt DelaySeconds;
}Upload;


/**
 *  Table 57 – UploadResponse arguments
 */
typedef struct UploadResponse_s {
    int Status[2];  //A successful response to this method returns an integer enumeration defined as follows:
                    //0 = Upload has completed.
                    //1 = Upload has not yet completed (for example, if the upload needs to wait until after the Session has been terminated).
    dateTime StartTime;
    dateTime CompleteTime;
}UploadResponse;


/**
 *  Table 58 – FactoryReset arguments
 */
typedef struct FactoryReset_s {
    //void-;
}FactoryReset;


/**
 *  Table 59 – FactoryResetResponse arguments
 */
typedef struct FactoryResetResponse_s {
    //void-;
}FactoryResetResponse;


/**
 *  Table 60 – GetAllQueuedTransfers arguments
 */
typedef struct GetAllQueuedTransfers_s {
    //void-;
}GetAllQueuedTransfers;


/**
 *  Table 62 – AllQueuedTransferStruct definition
 */
typedef struct AllQueuedTransferStruct_s {
    char CommandKey[32];
    int State[4];   //The current state of the transfer. Defined values are:
                    //1 = Not yet started
                    //2 = In progress
                    //3 = Completed, finishing cleanup
                    //All other values are reserved.
    boolean IsDownload;
    char FileType[64];  //"1 Firmware Upgrade Image" (download only)
                        //"2 Web Content" (download only)
                        //“3 Vendor Configuration File” (download or upload) [DEPRECATED for upload]
                        //“4 Vendor Log File” (upload only) [DEPRECATED]
                        //“4 Tone File” (download only; see [25] Appendix B)
                        //“5 Ringer File” (download only; see [25] Appendix B)
                        //“6 Vendor Configuration File <i>” (upload only)
                        //“7 Vendor Log File <i>” (upload only)
    unsignedInt FileSize;
    char TargetFileName[256];
}AllQueuedTransferStruct;


/**
 *  Table 61 – GetAllQueuedTransfersResponse arguments
 */
typedef struct GetAllQueuedTransfersResponse_s {
    AllQueuedTransferStruct TransferList[16];
}GetAllQueuedTransfersResponse;



/**
 *  Table 65 – TimeWindowStruct definition
 */
typedef struct TimeWindowStruct_s {
    unsignedInt WindowStart;
    unsignedInt WindowEnd;
    char WindowMode[64];    //An integer followed by a space followed by the time window mode description. 
                            //The following values are currently defined: 
                            //“1 At Any Time” 
                            //“2 Immediately” 
                            //“3 When Idle” 
                            //“4 Confirmation Needed” 
                            //The following format is defined to allow for the unique definition of vendor-specific time window modes: “X <VENDOR> <Vendor specific identifier>”
    char UserMessage[256];
    int MaxRetries;
}TimeWindowStruct;


/**
 *  Table 63 – ScheduleDownload arguments
 */
typedef struct ScheduleDownload_s {
    char CommandKey[32];
    char FileType[64];  //An integer followed by a space followed by the file type description. Only the following values are currently defined for the FileType argument:
                        //"1 Firmware Upgrade Image"
                        //"2 Web Content"
                        //“3 Vendor Configuration File”
                        //“4 Tone File” (see [25] Appendix B)
                        //“5 Ringer File” (see [25] Appendix B)
                        //The following format is defined to allow the unique definition of vendor-specific file types:
                        //"X <VENDOR> <Vendor-specific identifier>"
    char URL[256];
    char Username[256];
    char Password[256];
    unsignedInt FileSize;
    char TargetFileName[256];
    TimeWindowStruct TimeWindowList[3];
}ScheduleDownload;


/**
 *  Table 64 – ScheduleDownloadResponse arguments
 */
typedef struct ScheduleDownloadResponse_s {
    //vodi-;
}ScheduleDownloadResponse;


/**
 *  Table 66 – CancelTransfer arguments
 */
typedef struct CancelTransfer_s {
    char CommandKey[32];
}CancelTransfer;


/**
 *  Table 67 – CancelTransferResponse arguments
 */
typedef struct CancelTransferResponse_s {
    //void-
}CancelTransferResponse;


/**
 *  Table 70 – OperationStruct Types
 */
typedef struct OperationStruct_s {
    OperationStruct *InstallOpStruct;
    OperationStruct *UpdateOpStruct;
    OperationStruct *UninstallOpStruct;
}OperationStruct;

/**
 *  Table 68 – ChangeDUState Arguments
 */
typedef struct ChangeDUState_s {
    OperationStruct Operations;
    char CommandKey[32];
}ChangeDUState;



/**
 *  Table 69 – ChangeDUStateResponse Arguments
 */
typedef struct ChangeDUStateResponse_s {
    //void-;
}ChangeDUStateResponse;


/**
 *  Table 71 – InstallOpStruct Definition
 */
typedef struct InstallOpStruct_s {
    char URL[1024];
    char UUID[36];
    char Username[256];
    char Password[256];
    char ExecutionEnvRef[256];
}InstallOpStruct;


/**
 *  Table 72 – UpdateOpStruct Definition
 */
typedef struct UpdateOpStruct_s {
    char UUID[36];
    char Version[32];
    char URL[1024];
    char Username[256];
    char Password[256];    
}UpdateOpStruct;


/**
 *  Table 73 – UninstallOpStruct Definition
 */
typedef struct UninstallOpStruct_s {
    char UUID[36];
    char Version[32];
    char ExecutionEnvRef[256];
}UninstallOpStruct;


TODO("太多了，我太难了，我打算先看看开源代码，别万一做了无用功")




#endif /*<__TR069_RPC_H>*/
