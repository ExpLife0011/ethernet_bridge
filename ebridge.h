/*************************************************************************/
/*				Copyright (c) 2000-2016 NT Kernel Resources.		     */
/*                           All Rights Reserved.                        */
/*                          http://www.ntkernel.com                      */
/*                           ndisrd@ntkernel.com                         */
/*                                                                       */
/* Module Name:  EBridge.h												 */
/*                                                                       */
/* Abstract: Some NDIS helper definitions								 */
/*                                                                       */
/*************************************************************************/
#pragma once

enum class NetworkOid {
	//
	//  Required OIDs
	//
	OID_GEN_SUPPORTED_LIST = 0x00010101,
	OID_GEN_HARDWARE_STATUS = 0x00010102,
	OID_GEN_MEDIA_SUPPORTED = 0x00010103,
	OID_GEN_MEDIA_IN_USE = 0x00010104,
	OID_GEN_MAXIMUM_LOOKAHEAD = 0x00010105,
	OID_GEN_MAXIMUM_FRAME_SIZE = 0x00010106,
	OID_GEN_LINK_SPEED = 0x00010107,
	OID_GEN_TRANSMIT_BUFFER_SPACE = 0x00010108,
	OID_GEN_RECEIVE_BUFFER_SPACE = 0x00010109,
	OID_GEN_TRANSMIT_BLOCK_SIZE = 0x0001010A,
	OID_GEN_RECEIVE_BLOCK_SIZE = 0x0001010B,
	OID_GEN_VENDOR_ID = 0x0001010C,
	OID_GEN_VENDOR_DESCRIPTION = 0x0001010D,
	OID_GEN_CURRENT_PACKET_FILTER = 0x0001010E,
	OID_GEN_CURRENT_LOOKAHEAD = 0x0001010F,
	OID_GEN_DRIVER_VERSION = 0x00010110,
	OID_GEN_MAXIMUM_TOTAL_SIZE = 0x00010111,
	OID_GEN_PROTOCOL_OPTIONS = 0x00010112,
	OID_GEN_MAC_OPTIONS = 0x00010113,
	OID_GEN_MEDIA_CONNECT_STATUS = 0x00010114,
	OID_GEN_MAXIMUM_SEND_PACKETS = 0x00010115,

	//
	//  Optional OIDs
	//
	OID_GEN_VENDOR_DRIVER_VERSION = 0x00010116,
	OID_GEN_SUPPORTED_GUIDS = 0x00010117,
	OID_GEN_NETWORK_LAYER_ADDRESSES = 0x00010118, // Set only
	OID_GEN_TRANSPORT_HEADER_OFFSET = 0x00010119, // Set only
	OID_GEN_MEDIA_CAPABILITIES = 0x00010201,
	OID_GEN_PHYSICAL_MEDIUM = 0x00010202,
};


// Packet filter flags definitions
enum NetworkFilter {
	NDIS_PACKET_TYPE_DIRECTED = 0x00000001,
	NDIS_PACKET_TYPE_MULTICAST = 0x00000002,
	NDIS_PACKET_TYPE_ALL_MULTICAST = 0x00000004,
	NDIS_PACKET_TYPE_BROADCAST = 0x00000008,
	NDIS_PACKET_TYPE_SOURCE_ROUTING = 0x00000010,
	NDIS_PACKET_TYPE_PROMISCUOUS = 0x00000020,
	NDIS_PACKET_TYPE_SMT = 0x00000040,
	NDIS_PACKET_TYPE_ALL_LOCAL = 0x00000080,
	NDIS_PACKET_TYPE_GROUP = 0x00001000,
	NDIS_PACKET_TYPE_ALL_FUNCTIONAL = 0x00002000,
	NDIS_PACKET_TYPE_FUNCTIONAL = 0x00004000,
	NDIS_PACKET_TYPE_MAC_FRAME = 0x00008000
};


class EthernetBridge : public CNdisApi
{
public:
	EthernetBridge() : CNdisApi() { InitializeNetworkInterfaces(); }
	virtual ~EthernetBridge() { StopBridge(); }

	void StartBridge(size_t First, size_t Second);
	void StopBridge();
	std::vector<string> GetInterfaceList();

private:
	static const size_t ThreadCount = 2;
	static void BridgeWorkingThread(EthernetBridge*, size_t, size_t);

	void InitializeNetworkInterfaces();

	std::atomic_flag m_bIsRunning = ATOMIC_FLAG_INIT;
	std::vector<unique_ptr<CNetworkAdapter>> m_NetworkInterfaces; // List of network interfaces available for bridging
	std::vector<std::thread> m_WorkingThreads;
	std::pair<std::size_t, std::size_t> m_BridgedInterfaces;
};