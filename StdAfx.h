/*************************************************************************/
/*				Copyright (c) 2000-2016 NT Kernel Resources.		     */
/*                           All Rights Reserved.                        */
/*                          http://www.ntkernel.com                      */
/*                           ndisrd@ntkernel.com                         */
/*                                                                       */
/* Module Name:  stdafx.h                                                */
/*                                                                       */
/* Abstract: include file for standard system include files,             */
/*  or project specific include files that are used frequently, but      */
/*  are changed infrequently                                             */
/*                                                                       */
/*************************************************************************/

#if !defined(AFX_STDAFX_H__090BD577_3479_4129_82EA_36B3F0A5D7E9__INCLUDED_)
#define AFX_STDAFX_H__090BD577_3479_4129_82EA_36B3F0A5D7E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#endif // WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <iphlpapi.h>
#include <process.h>
#include <conio.h>
#include <WinSock2.h>

#include <utility>
#include <vector>
#include <unordered_map>
#include <memory>
#include <tuple>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

#define _WINDOWS
#include "..\..\..\include\common.h"
#include "ndisapi.h"
#include "iphlp.h"
#include "dhcp_typedefs.h"
#include "NetworkAdapter.h"
#include "ebridge.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__090BD577_3479_4129_82EA_36B3F0A5D7E9__INCLUDED_)
