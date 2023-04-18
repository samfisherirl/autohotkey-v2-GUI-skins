; Dll文件在此下载 https://github.com/CodyGuo/skinh
; 官方说明与皮肤文件 http://www.skinsharp.com/htdocs/docs.htm

#SingleInstance Force

; 强制使用32位运行
if !(1 = 1 and A_PtrSize = 4)
{
	Run(A_ScriptDir "\AutoHotkeyU32.exe `"" A_ScriptFullPath "`"") ;Must run 32bit
	; Run either 32bit AHKV2
	ExitApp()
}


hSkinH := DllCall("LoadLibrary", "Str", "SkinHu.dll")
changeSkin(A_ScriptDir "\skins\aero.she")

changeSkin(skinPath) {
	DllCall("SkinHu\SkinH_AttachEx", "Str", skinPath, "Str", "mhgd")
}


; ███████╗██╗  ██╗██╗███╗   ██╗███████╗██╗  ██╗ █████╗ ██████╗ ██████╗ 
; ██╔════╝██║ ██╔╝██║████╗  ██║██╔════╝██║  ██║██╔══██╗██╔══██╗██╔══██╗
; ███████╗█████╔╝ ██║██╔██╗ ██║███████╗███████║███████║██████╔╝██████╔╝
; ╚════██║██╔═██╗ ██║██║╚██╗██║╚════██║██╔══██║██╔══██║██╔══██╗██╔═══╝ 
; ███████║██║  ██╗██║██║ ╚████║███████║██║  ██║██║  ██║██║  ██║██║     
; ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     

FileMenu := Menu()
FileMenu.Add("test1", MenuHandler)
FileMenu.Add("test2", MenuHandler)
FileMenu.Add("test3", MenuHandler)
FileMenu.Add("test4", MenuHandler)
FileMenu.Add("test5", MenuHandler)
FileMenu.Add("test6", MenuHandler)
MenBar := Menu()
MenBar.Add("&File", FileMenu)
MenBar.Add("&Test", testMenu)
myGui := Gui()
myGui.OnEvent("Close", GuiEscape)
myGui.OnEvent("Escape", GuiEscape)
myGui.MenBar := MenBar
ContextMen := Menu()
ContextMen.Add("&Open...`tCtrl+O", MenuHandler)
ContextMen.Add("&Save`tCtrl+S", MenuHandler)

; 显示皮肤文件
myGui.Add("GroupBox", "x24 y8 w248 h650", "控件演示")
ogcListViewlv := myGui.Add("ListView", "x40 y40 w215 h586  vlv AltSubmit", ["皮肤"])
ogcListViewlv.OnEvent("Click", change)
Loop Files, "skins\*.she"																	; 从文件夹中获取文件名列表并把它们放入 ListView:
	ogcListViewlv.Add("", A_LoopFileName)
ogcListViewlv.ModifyCol()																		; 根据内容自动调整每列的大小.

; 下面全是右侧演示控件
Tab := myGui.Add("Tab3", "x288 y8 w495 h650", ["Tab 1", "Tab 2"])

myGui.Add("Text", "x336 y45 w96 h24", "Some Text")
myGui.Add("Link", "x472 y45 w96 h24", "<a href=`"https://autohotkey.com`">autohotkey.com</a>")
myGui.Add("ComboBox", "x608 y40 w120", ["combobox"])

myGui.Add("Checkbox", "x336 y80 w96 h24", "checkbox")
myGui.Add("Radio", "x472 y80 w96 h24", "radiobutton")
myGui.Add("DropDownList", "x608 y80 w120", ["DropDownList", "123", "456"])

myGui.Add("Edit", "x336 y120 w96 h24", "edit")
myGui.Add("UpDown", "x432 y120 w17 h24 -16", "1")
myGui.Add("Hotkey", "x608 y120 w120 h20")

myGui.Add("Progress", "x336 y160 w233 h24", "50")
myGui.Add("Slider", "x336 y200 w233 h24", "50")
ogcButton := myGui.Add("Button", "x608 y160 w120 h65", "Get code template")

ogcListViewRedGreen := myGui.Add("ListView", "x336 y240 w120 h148", ["Red", "Green", ""])
ogcListViewRedGreen.OnEvent("DoubleClick", change)
myGui.Add("ListBox", "x472 y240 w120 h148", ["Red", "Green", "Blue", "Black", "White"])
ogcTreeView := myGui.Add("TreeView", "x608 y240 w120 h148")
P1 := ogcTreeView.Add("First parent")
P1C1 := ogcTreeView.Add("Parent 1's first child", P1)  ; 指定 P1 为此项目的父项目.
P2 := ogcTreeView.Add("Second parent")
P2C1 := ogcTreeView.Add("Parent 2's first child", P2)
P2C2 := ogcTreeView.Add("Parent 2's second child", P2)
P2C2C1 := ogcTreeView.Add("Child 2's first child", P2C2)

myGui.Add("Text", "x336 y408 w398 h2 +0x10")

myGui.Add("DateTime", "x336 y424 w225 h20", "2021-01-29")
myGui.Add("MonthCal", "x336 y448 w225 h176")
SB := myGui.Add("StatusBar", , "Status Bar")

	; 设置换肤里的 LV_GetText() 函数默认操作第一个 ListView
myGui.Title := "换肤测试"
myGui.Show("w805 h694")
Return

change(ogcListViewRedGreen, RowNumber)
{ ; V1toV2: Added bracket
	OutputVar := ogcListViewRedGreen.GetText(RowNumber)
	hSkinH := DllCall("LoadLibrary", "Str", "SkinHu.dll")

	DllCall("SkinHu\SkinH_AttachEx", "Str", A_ScriptDir "\skins\" OutputVar, "Str", "mhgd")
	Return
} ; V1toV2: Added bracket before function

MenuHandler(A_ThisMenuItem, A_ThisMenuItemPos, MyMenu)
{ ; V1toV2: Added bracket
	Return
} ; V1toV2: Added Bracket before label
testMenu(A_ThisMenuItem, A_ThisMenuItemPos, MyMenu)
{ ; V1toV2: Added bracket
	Return
} ; V1toV2: Added Bracket before label

GuiEscape(*)
{ ; V1toV2: Added bracket
GuiClose:
	ExitApp()
	Return
} ; V1toV2: Added bracket in the end

