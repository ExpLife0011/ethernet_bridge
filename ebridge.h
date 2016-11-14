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

	volatile bool m_bIsRunning = true;
	std::vector<unique_ptr<CNetworkAdapter>> m_NetworkInterfaces; // List of network interfaces available for bridging
	std::vector<std::thread> m_WorkingThreads;
	std::pair<std::size_t, std::size_t> m_BridgedInterfaces;

public:
	static void RecalculateIPChecksum(iphdr_ptr pIpHeader);
	static void RecalculateUDPChecksum(PINTERMEDIATE_BUFFER pPacket);
};