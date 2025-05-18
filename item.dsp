# Microsoft Developer Studio Project File - Name="item" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=item - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "item.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "item.mak" CFG="item - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "item - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "item - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "item - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "item - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "item - Win32 Release"
# Name "item - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Appointment.cpp
# End Source File
# Begin Source File

SOURCE=.\CAddDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CAdminManageDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CAdminSearchDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CAdminSearchRoomWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CAdminSearchStaffWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CAdminWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CButton.cpp
# End Source File
# Begin Source File

SOURCE=.\CData.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiagnose.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctor.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorAmendPwdWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorSearchStaffWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorWriteWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CEditbox.cpp
# End Source File
# Begin Source File

SOURCE=.\CKRoom.cpp
# End Source File
# Begin Source File

SOURCE=.\CLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\CLoginWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CManagerWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CPullDown.cpp
# End Source File
# Begin Source File

SOURCE=.\CSignupWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaff.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffAmendInfoWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffAmendPwdWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffAppointmentManagerWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffGetNumWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffOutpatientWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffPersonalCenterWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffSearchDiagnoseWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CStaffWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CTools.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlBase.cpp
# End Source File
# Begin Source File

SOURCE=.\CWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\mainWin.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Appointment.h
# End Source File
# Begin Source File

SOURCE=.\CAddDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\CAdminManageDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\CAdminSearchDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\CAdminSearchRoomWin.h
# End Source File
# Begin Source File

SOURCE=.\CAdminSearchStaffWin.h
# End Source File
# Begin Source File

SOURCE=.\CAdminWin.h
# End Source File
# Begin Source File

SOURCE=.\CButton.h
# End Source File
# Begin Source File

SOURCE=.\CData.h
# End Source File
# Begin Source File

SOURCE=.\CDiagnose.h
# End Source File
# Begin Source File

SOURCE=.\CDoctor.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorAmendPwdWin.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorSearchStaffWin.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorWriteWin.h
# End Source File
# Begin Source File

SOURCE=.\CEditbox.h
# End Source File
# Begin Source File

SOURCE=.\CKRoom.h
# End Source File
# Begin Source File

SOURCE=.\CLabel.h
# End Source File
# Begin Source File

SOURCE=.\CLoginWin.h
# End Source File
# Begin Source File

SOURCE=.\CManagerWin.h
# End Source File
# Begin Source File

SOURCE=.\CPullDown.h
# End Source File
# Begin Source File

SOURCE=.\CSignupWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaff.h
# End Source File
# Begin Source File

SOURCE=.\CStaffAmendInfoWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffAmendPwdWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffAppointmentManagerWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffGetNumWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffOutpatientWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffPersonalCenterWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffSearchDiagnoseWin.h
# End Source File
# Begin Source File

SOURCE=.\CStaffWin.h
# End Source File
# Begin Source File

SOURCE=.\CTable.h
# End Source File
# Begin Source File

SOURCE=.\CTools.h
# End Source File
# Begin Source File

SOURCE=.\CtrlBase.h
# End Source File
# Begin Source File

SOURCE=.\CWindow.h
# End Source File
# Begin Source File

SOURCE=.\mainWin.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
