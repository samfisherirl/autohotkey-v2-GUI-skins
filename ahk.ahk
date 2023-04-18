hSkinH := DllCall("LoadLibrary", "Str", "SkinHu.dll")
DllCall("SkinHu\SkinH_AttachEx", "Str", A_ScriptDir "\skins\skinh.she")