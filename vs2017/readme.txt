How to modify project property to support WxWidgets and ToolbitSDK


C/C++ -> General -> Additional Include Directories
Add the following line
..\include;..\..\wxWidgets-master\include;..\..\wxWidgets-master\lib\vc_lib\mswud


Linker -> General -> Additional Library Directories
Add the following line
..\..\wxWidgets-master\lib\vc_lib;..\..\ToolbitSDK\lib\vs


Linker -> Input -> Additional Dependencies
Add the following line
libtbi.lib;setupapi.lib;wxmsw31ud_core.lib;wxbase31ud.lib;wxtiffd.lib;wxjpegd.lib;wxpngd.lib;wxzlibd.lib;wxregexud.lib;wxexpatd.lib;winmm.lib;comctl32.lib;rpcrt4.lib;wsock32.lib;wininet.lib;%(AdditionalDependencies)


