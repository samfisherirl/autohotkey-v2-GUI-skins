; Cool preview gui script written by 'garry'

#NoEnv
#SingleInstance force

setworkingdir,%a_scriptdir%
Gui,1:default
f2=%a_scriptdir%\GuiStyle_Soft.ahk
RSSINI=%A_scriptdir%\RSSINI.ini
Loop, %a_scriptdir%\*.she,,1
  e .= A_LoopFileFullPath . "`r`n"
n=0
z=0
Gui,1:Font, CDefault, FixedSys
Gui,1:Color,Black

;- use button Next
;  or
;- use gosub next2 which displays for 5 seconds

Gui,1:add,edit    ,x10 y10 h25 w120 vE1 readonly cYellow,
Gui,1:add,button  ,x10 y50 h25 w100 gNextx,NEXT>
Gui,1:show, x200 y400 h90 w140
gosub,create2
;gosub,next2
return


nextx:
Gui,1:submit,nohide
n++
Loop,parse,e,`n,`r
 {
 z++
 y:=A_LoopField
 if (y="")
    {
    n:=(n-1)
    GuiControl,1:,e1,%n%-styles END
    n=0
    return
    }
 if (n=z)
    {
    z=0
    break
    }
 }
IniWrite,%y%   , %rssini% ,A1   , KEY1
SplitPath,y,name, dir, ext, name_no_ext, drive
run,%f2%
GuiControl,1:,e1, %name_no_ext%
return

;--------------
next2:
Gui,1:submit,nohide
Loop,parse,e,`n,`r
 {
 y:=A_LoopField
 if (y="")
   continue
 ;msgbox, 262208, ,%y% ,
 IniWrite,%y%   , %rssini% ,A1   , KEY1
 SplitPath,y,name, dir, ext, name_no_ext, drive
 run,%f2%
 GuiControl,1:,e1, %name_no_ext%
 sleep,5000
 }
return

Guiclose:
exitapp
;---------------------------------------
create2:
Gui,1:submit,nohide
e4x=
(
#NoEnv
#SingleInstance force
pr:= a_scriptdir . "\SkinH_EL.dll"
IniRead, aa1, %rssini% , A1 , Key1
aa1:= aa1
SkinForm(Apply,pr,aa1)

OnExit, GetOut
Gui,2: add, button,xm w100 h40, Button
Gui,2: add, edit, xm y+20 w100 h20, Edit
Gui,2: add, listbox,xm y+20, ListBox
Gui,2: add, checkbox,xm y+20, checkbox
Gui,2: add, DDL, xm y+20, DropDownList
Gui,2: Show, w200 , GUI_Style
return
;-----------------------------------

GetOut:
2GuiClose:
Gui,2: Hide
SkinForm(0)
ExitApp
;-----------------------------------

SkinForm(Param1 = "Apply", DLL = "", SkinName = ""){
    if(Param1 = Apply){
        DllCall("LoadLibrary", str, DLL)
        DllCall(DLL . "\SkinH_AttachEx", AStr,SkinName, Str,"mhgd")
    }else if(Param1 = 0){
        DllCall(DLL . "\USkinExit")
        }
}
)
ifnotexist,%f2%
  fileappend,%e4x%,%f2%
e4x=
return
;========================================================


