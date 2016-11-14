/*************************************************************************/
/*				Copyright (c) 2000-2016 NT Kernel Resources.		     */
/*                           All Rights Reserved.                        */
/*                          http://www.ntkernel.com                      */
/*                           ndisrd@ntkernel.com                         */
/*																		 */
/* Description: API exported C++ class declaration						 */
/*************************************************************************/

//
// Medium the Ndis Driver is running on (OID_GEN_MEDIA_SUPPORTED/ OID_GEN_MEDIA_IN_USE).
//
enum class NdisMedium
{
	NdisMedium802_3,
	NdisMedium802_5,
	NdisMediumFddi,
	NdisMediumWan,
	NdisMediumLocalTalk,
	NdisMediumDix,              // defined for convenience, not a real medium
	NdisMediumArcnetRaw,
	NdisMediumArcnet878_2,
	NdisMediumAtm,
	NdisMediumWirelessWan,
	NdisMediumIrda,
	NdisMediumBpc,
	NdisMediumCoWan,
	NdisMedium1394,
	NdisMediumInfiniBand,
	NdisMediumTunnel,
	NdisMediumNative802_11,
	NdisMediumLoopback,
	NdisMediumWiMAX,
	NdisMediumIP,
	NdisMediumMax               // Not a real medium, defined as an upper-bound
};

//
// Physical Medium Type definitions. Used with OID_GEN_PHYSICAL_MEDIUM.
//
enum class NdisPhysicalMedium
{
	NdisPhysicalMediumUnspecified,
	NdisPhysicalMediumWirelessLan,
	NdisPhysicalMediumCableModem,
	NdisPhysicalMediumPhoneLine,
	NdisPhysicalMediumPowerLine,
	NdisPhysicalMediumDSL,      // includes ADSL and UADSL (G.Lite)
	NdisPhysicalMediumFibreChannel,
	NdisPhysicalMedium1394,
	NdisPhysicalMediumWirelessWan,
	NdisPhysicalMediumNative802_11,
	NdisPhysicalMediumBluetooth,
	NdisPhysicalMediumInfiniband,
	NdisPhysicalMediumWiMax,
	NdisPhysicalMediumUWB,
	NdisPhysicalMedium802_3,
	NdisPhysicalMedium802_5,
	NdisPhysicalMediumIrda,
	NdisPhysicalMediumWiredWAN,
	NdisPhysicalMediumWiredCoWan,
	NdisPhysicalMediumOther,
	NdisPhysicalMediumMax       // Not a real physical type, defined as an upper-bound
};


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

enum
{
	FILE_NAME_SIZE = 1000
};

typedef BOOL (__stdcall *IsWow64ProcessPtr)(HANDLE hProcess, PBOOL Wow64Process);

class CNdisApi 
{
public:
	CNdisApi (const TCHAR* pszFileName = _T(DRIVER_NAME_A));
	virtual ~CNdisApi ();

private:
	// Private member functions
	BOOL	DeviceIoControl (DWORD dwService, void *BuffIn, int SizeIn, void *BuffOut, int SizeOut, unsigned long *SizeRet = NULL, LPOVERLAPPED povlp = NULL) const;

public:
	// Driver services
	ULONG	GetVersion () const;
	BOOL	GetTcpipBoundAdaptersInfo ( PTCP_AdapterList pAdapters ) const;
	BOOL	SendPacketToMstcp ( PETH_REQUEST pPacket ) const;
	BOOL	SendPacketToAdapter ( PETH_REQUEST pPacket ) const;
	BOOL	ReadPacket ( PETH_REQUEST pPacket ) const;
	BOOL	SendPacketsToMstcp (PETH_M_REQUEST pPackets) const;
	BOOL	SendPacketsToAdapter(PETH_M_REQUEST pPackets) const;
	BOOL	ReadPackets(PETH_M_REQUEST pPackets) const;
	BOOL	SetAdapterMode ( PADAPTER_MODE pMode ) const;
	BOOL	GetAdapterMode ( PADAPTER_MODE pMode ) const;
	BOOL	FlushAdapterPacketQueue ( HANDLE hAdapter ) const;
	BOOL	GetAdapterPacketQueueSize ( HANDLE hAdapter, PDWORD pdwSize ) const;
	BOOL	SetPacketEvent ( HANDLE hAdapter, HANDLE hWin32Event ) const;
	BOOL	SetWANEvent ( HANDLE hWin32Event ) const;
	BOOL	SetAdapterListChangeEvent ( HANDLE hWin32Event ) const;
	BOOL	NdisrdRequest ( PPACKET_OID_DATA OidData, BOOL Set ) const;
	BOOL	GetRasLinks (HANDLE hAdapter, PRAS_LINKS pLinks) const;
	BOOL	SetHwPacketFilter ( HANDLE hAdapter, DWORD Filter ) const;
	BOOL	GetHwPacketFilter ( HANDLE hAdapter, PDWORD pFilter ) const;
	BOOL	SetPacketFilterTable (PSTATIC_FILTER_TABLE pFilterList ) const;
	BOOL	ResetPacketFilterTable () const;
	BOOL	GetPacketFilterTableSize ( PDWORD pdwTableSize ) const;
	BOOL	GetPacketFilterTable ( PSTATIC_FILTER_TABLE pFilterList ) const;
	BOOL	GetPacketFilterTableResetStats ( PSTATIC_FILTER_TABLE pFilterList ) const;
	
	static BOOL		SetMTUDecrement ( DWORD dwMTUDecrement );
	static DWORD	GetMTUDecrement ();

	static BOOL		SetAdaptersStartupMode ( DWORD dwStartupMode );
	static DWORD	GetAdaptersStartupMode ();

	BOOL	IsDriverLoaded () const;
	DWORD	GetBytesReturned () const;

	// Statuc helper routines
	static BOOL
		ConvertWindowsNTAdapterName (
			LPCSTR szAdapterName,
			LPSTR szUserFriendlyName,
			DWORD dwUserFriendlyNameLength
			);

	static BOOL
		ConvertWindows2000AdapterName (
			LPCSTR szAdapterName,
			LPSTR szUserFriendlyName,
			DWORD dwUserFriendlyNameLength
			);

	static BOOL
		ConvertWindows9xAdapterName (
			LPCSTR szAdapterName,
			LPSTR szUserFriendlyName,
			DWORD dwUserFriendlyNameLength
			);

private:
	// Private member variables
	mutable OVERLAPPED				m_ovlp;
	mutable DWORD					m_BytesReturned;
	mutable TCP_AdapterList_WOW64	m_AdaptersList;

	HANDLE					m_hFileHandle;
	BOOL					m_bIsLoadSuccessfully;
	OSVERSIONINFO			m_Version;
	IsWow64ProcessPtr		m_pfnIsWow64Process;
	BOOL					m_bIsWow64Process;
};