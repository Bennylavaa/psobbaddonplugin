#pragma warning (disable : 4244)

//    IMGUI_API ImGuiIO&      GetIO();
// Unsupported return type ImGuiIO&
//    IMGUI_API ImGuiStyle&   GetStyle();
// Unsupported return type ImGuiStyle&
//    IMGUI_API ImDrawData*   GetDrawData();                              // same value as passed to your io.RenderDrawListsFn() function. valid after Render() and until the next call to NewFrame()
// Unsupported return type ImDrawData*
//    IMGUI_API void          NewFrame();                                 // start a new ImGui frame, you can submit any command from this point until NewFrame()/Render().
//Not allowed to use this function
//    IMGUI_API void          Render();                                   // ends the ImGui frame, finalize rendering data, then call your io.RenderDrawListsFn() function if set.
IMGUI_FUNCTION(Render)
CALL_FUNCTION_NO_RET(Render)
END_IMGUI_FUNC
//    IMGUI_API void          Shutdown();
//Not allowed to use this function
//    IMGUI_API void          ShowUserGuide();                            // help block
IMGUI_FUNCTION(ShowUserGuide)
CALL_FUNCTION_NO_RET(ShowUserGuide)
END_IMGUI_FUNC
//    IMGUI_API void          ShowStyleEditor(ImGuiStyle* ref = NULL);    // style editor block. you can pass in a reference ImGuiStyle structure to compare to, revert to and save to (else it uses the default style)
IMGUI_FUNCTION(ShowStyleEditor)
DEFAULT_ARG(ImGuiStyle*, ref, NULL)
CALL_FUNCTION_NO_RET(ShowStyleEditor, ref)
END_IMGUI_FUNC
//    IMGUI_API void          ShowTestWindow(bool* p_open = NULL);        // test window demonstrating ImGui features
IMGUI_FUNCTION(ShowTestWindow)
OPTIONAL_BOOL_POINTER_ARG(p_open)
CALL_FUNCTION_NO_RET(ShowTestWindow, p_open)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC
//    IMGUI_API void          ShowMetricsWindow(bool* p_open = NULL);     // metrics window for debugging ImGui
IMGUI_FUNCTION(ShowMetricsWindow)
OPTIONAL_BOOL_POINTER_ARG(p_open)
CALL_FUNCTION_NO_RET(ShowMetricsWindow, p_open)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC
//    IMGUI_API bool          Begin(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0);                                                   // push window to the stack and start appending to it. see .cpp for details. return false when window is collapsed, so you can early out in your code. 'bool* p_open' creates a widget on the upper-right to close the window (which sets your bool to false).
IMGUI_FUNCTION(Begin)
LABEL_ARG(name)
OPTIONAL_BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(Begin, bool, name, p_open, flags)
IF_RET_ADD_END_STACK(0)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC
//    IMGUI_API bool          Begin(const char* name, bool* p_open, const ImVec2& size_on_first_use, float bg_alpha = -1.0f, ImGuiWindowFlags flags = 0); // OBSOLETE. this is the older/longer API. the extra parameters aren't very relevant. call SetNextWindowSize() instead if you want to set a window size. For regular windows, 'size_on_first_use' only applies to the first time EVER the window is created and probably not what you want! might obsolete this API eventually.
IMGUI_FUNCTION(Begin_2)
LABEL_ARG(name)
BOOL_POINTER_ARG(p_open)
IM_VEC_2_ARG(size_on_first_use)
OPTIONAL_NUMBER_ARG(bg_alpha, -1.0f)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(Begin, bool, name, p_open, size_on_first_use, bg_alpha, flags)
IF_RET_ADD_END_STACK(0)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC
//    IMGUI_API void          End();                                                                                                                      // finish appending to current window, pop it off the window stack.
IMGUI_FUNCTION(End)
CALL_FUNCTION_NO_RET(End)
POP_END_STACK(0)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginChild(const char* str_id, const ImVec2& size = ImVec2 0 0, bool border = false, ImGuiWindowFlags extra_flags = 0);    // begin a scrolling region. size==0.0f: use remaining window size, size<0.0f: use remaining window size minus abs(size). size>0.0f: fixed size. each axis can use a different mode, e.g. ImVec2 0 400.
IMGUI_FUNCTION(BeginChild)
LABEL_ARG(str_id)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
OPTIONAL_BOOL_ARG(border, false)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(BeginChild, bool, str_id, size, border, extra_flags)
IF_RET_ADD_END_STACK(1)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginChild(ImGuiID id, const ImVec2& size = ImVec2 0 0, bool border = false, ImGuiWindowFlags extra_flags = 0);            // "
IMGUI_FUNCTION(BeginChild_2)
UINT_ARG(id)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
OPTIONAL_BOOL_ARG(border, false)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(BeginChild, bool, id, size, border, extra_flags)
IF_RET_ADD_END_STACK(1)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          EndChild();
IMGUI_FUNCTION(EndChild)
CALL_FUNCTION_NO_RET(EndChild)
POP_END_STACK(1)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetContentRegionMax();                                              // current content boundaries (typically window boundaries including scrolling, or current column boundaries), in windows coordinates
IMGUI_FUNCTION(GetContentRegionMax)
CALL_FUNCTION(GetContentRegionMax, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetContentRegionAvail();                                            // == GetContentRegionMax() - GetCursorPos()
IMGUI_FUNCTION(GetContentRegionAvail)
CALL_FUNCTION(GetContentRegionAvail, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API float         GetContentRegionAvailWidth();                                       //
IMGUI_FUNCTION(GetContentRegionAvailWidth)
CALL_FUNCTION(GetContentRegionAvailWidth, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetWindowContentRegionMin();                                        // content boundaries min (roughly (0,0)-Scroll), in window coordinates
IMGUI_FUNCTION(GetWindowContentRegionMin)
CALL_FUNCTION(GetWindowContentRegionMin, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetWindowContentRegionMax();                                        // content boundaries max (roughly (0,0)+Size-Scroll) where Size can be override with SetNextWindowContentSize(), in window coordinates
IMGUI_FUNCTION(GetWindowContentRegionMax)
CALL_FUNCTION(GetWindowContentRegionMax, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API float         GetWindowContentRegionWidth();                                      //
IMGUI_FUNCTION(GetWindowContentRegionWidth)
CALL_FUNCTION(GetWindowContentRegionWidth, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API ImDrawList*   GetWindowDrawList();                                                // get rendering command-list if you want to append your own draw primitives
// Unsupported return type ImDrawList*
//    IMGUI_API ImVec2        GetWindowPos();                                                     // get current window position in screen space (useful if you want to do your own drawing via the DrawList api)
IMGUI_FUNCTION(GetWindowPos)
CALL_FUNCTION(GetWindowPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetWindowSize();                                                    // get current window size
IMGUI_FUNCTION(GetWindowSize)
CALL_FUNCTION(GetWindowSize, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API float         GetWindowWidth();
IMGUI_FUNCTION(GetWindowWidth)
CALL_FUNCTION(GetWindowWidth, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetWindowHeight();
IMGUI_FUNCTION(GetWindowHeight)
CALL_FUNCTION(GetWindowHeight, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsWindowCollapsed();
IMGUI_FUNCTION(IsWindowCollapsed)
CALL_FUNCTION(IsWindowCollapsed, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowFontScale(float scale);                                    // per-window font scale. Adjust IO.FontGlobalScale if you want to scale all windows
IMGUI_FUNCTION(SetWindowFontScale)
NUMBER_ARG(scale)
CALL_FUNCTION_NO_RET(SetWindowFontScale, scale)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowPos(const ImVec2& pos, ImGuiSetCond cond = 0);         // set next window position. call before Begin()
IMGUI_FUNCTION(SetNextWindowPos)
IM_VEC_2_ARG(pos)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowPos, pos, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowPosCenter(ImGuiSetCond cond = 0);                      // set next window position to be centered on screen. call before Begin()
IMGUI_FUNCTION(SetNextWindowPosCenter)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowPosCenter, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowSize(const ImVec2& size, ImGuiSetCond cond = 0);       // set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin()
IMGUI_FUNCTION(SetNextWindowSize)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowSize, size, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowSizeConstraints(const ImVec2& size_min, const ImVec2& size_max, ImGuiSizeConstraintCallback custom_callback = NULL, void* custom_callback_data = NULL); // set next window size limits. use -1,-1 on either X/Y axis to preserve the current size. Use callback to apply non-trivial programmatic constraints.
IMGUI_FUNCTION(SetNextWindowSizeConstraints)
IM_VEC_2_ARG(size_min)
IM_VEC_2_ARG(size_max)
DEFAULT_ARG(ImGuiSizeConstraintCallback, custom_callback, NULL)
DEFAULT_ARG(void*, custom_callback_data, NULL)
CALL_FUNCTION_NO_RET(SetNextWindowSizeConstraints, size_min, size_max, custom_callback, custom_callback_data)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowContentSize(const ImVec2& size);                       // set next window content size (enforce the range of scrollbars). set axis to 0.0f to leave it automatic. call before Begin()
IMGUI_FUNCTION(SetNextWindowContentSize)
IM_VEC_2_ARG(size)
CALL_FUNCTION_NO_RET(SetNextWindowContentSize, size)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowContentWidth(float width);                             // set next window content width (enforce the range of horizontal scrollbar). call before Begin()
IMGUI_FUNCTION(SetNextWindowContentWidth)
NUMBER_ARG(width)
CALL_FUNCTION_NO_RET(SetNextWindowContentWidth, width)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowCollapsed(bool collapsed, ImGuiSetCond cond = 0);      // set next window collapsed state. call before Begin()
IMGUI_FUNCTION(SetNextWindowCollapsed)
BOOL_ARG(collapsed)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowCollapsed, collapsed, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextWindowFocus();                                               // set next window to be focused / front-most. call before Begin()
IMGUI_FUNCTION(SetNextWindowFocus)
CALL_FUNCTION_NO_RET(SetNextWindowFocus)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowPos(const ImVec2& pos, ImGuiSetCond cond = 0);             // (not recommended) set current window position - call within Begin()/End(). prefer using SetNextWindowPos(), as this may incur tearing and side-effects.
IMGUI_FUNCTION(SetWindowPos)
IM_VEC_2_ARG(pos)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowPos, pos, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowSize(const ImVec2& size, ImGuiSetCond cond = 0);           // (not recommended) set current window size - call within Begin()/End(). set to ImVec2 0 0 to force an auto-fit. prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects.
IMGUI_FUNCTION(SetWindowSize)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowSize, size, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowCollapsed(bool collapsed, ImGuiSetCond cond = 0);          // (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed().
IMGUI_FUNCTION(SetWindowCollapsed)
BOOL_ARG(collapsed)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowCollapsed, collapsed, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowFocus();                                                   // (not recommended) set current window to be focused / front-most. prefer using SetNextWindowFocus().
IMGUI_FUNCTION(SetWindowFocus)
CALL_FUNCTION_NO_RET(SetWindowFocus)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowPos(const char* name, const ImVec2& pos, ImGuiSetCond cond = 0);      // set named window position.
IMGUI_FUNCTION(SetWindowPos_2)
LABEL_ARG(name)
IM_VEC_2_ARG(pos)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowPos, name, pos, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowSize(const char* name, const ImVec2& size, ImGuiSetCond cond = 0);    // set named window size. set axis to 0.0f to force an auto-fit on this axis.
IMGUI_FUNCTION(SetWindowSize_2)
LABEL_ARG(name)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowSize, name, size, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowCollapsed(const char* name, bool collapsed, ImGuiSetCond cond = 0);   // set named window collapsed state
IMGUI_FUNCTION(SetWindowCollapsed_2)
LABEL_ARG(name)
BOOL_ARG(collapsed)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowCollapsed, name, collapsed, cond)
END_IMGUI_FUNC
//    IMGUI_API void          SetWindowFocus(const char* name);                                              // set named window to be focused / front-most. use NULL to remove focus.
IMGUI_FUNCTION(SetWindowFocus_2)
LABEL_ARG(name)
CALL_FUNCTION_NO_RET(SetWindowFocus, name)
END_IMGUI_FUNC
//    IMGUI_API float         GetScrollX();                                                       // get scrolling amount [0..GetScrollMaxX()]
IMGUI_FUNCTION(GetScrollX)
CALL_FUNCTION(GetScrollX, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetScrollY();                                                       // get scrolling amount [0..GetScrollMaxY()]
IMGUI_FUNCTION(GetScrollY)
CALL_FUNCTION(GetScrollY, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetScrollMaxX();                                                    // get maximum scrolling amount ~~ ContentSize.X - WindowSize.X
IMGUI_FUNCTION(GetScrollMaxX)
CALL_FUNCTION(GetScrollMaxX, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetScrollMaxY();                                                    // get maximum scrolling amount ~~ ContentSize.Y - WindowSize.Y
IMGUI_FUNCTION(GetScrollMaxY)
CALL_FUNCTION(GetScrollMaxY, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          SetScrollX(float scroll_x);                                         // set scrolling amount [0..GetScrollMaxX()]
IMGUI_FUNCTION(SetScrollX)
NUMBER_ARG(scroll_x)
CALL_FUNCTION_NO_RET(SetScrollX, scroll_x)
END_IMGUI_FUNC
//    IMGUI_API void          SetScrollY(float scroll_y);                                         // set scrolling amount [0..GetScrollMaxY()]
IMGUI_FUNCTION(SetScrollY)
NUMBER_ARG(scroll_y)
CALL_FUNCTION_NO_RET(SetScrollY, scroll_y)
END_IMGUI_FUNC
//    IMGUI_API void          SetScrollHere(float center_y_ratio = 0.5f);                         // adjust scrolling amount to make current cursor position visible. center_y_ratio=0.0: top, 0.5: center, 1.0: bottom.
IMGUI_FUNCTION(SetScrollHere)
OPTIONAL_NUMBER_ARG(center_y_ratio, 0.5f)
CALL_FUNCTION_NO_RET(SetScrollHere, center_y_ratio)
END_IMGUI_FUNC
//    IMGUI_API void          SetScrollFromPosY(float pos_y, float center_y_ratio = 0.5f);        // adjust scrolling amount to make given position valid. use GetCursorPos() or GetCursorStartPos()+offset to get valid positions.
IMGUI_FUNCTION(SetScrollFromPosY)
NUMBER_ARG(pos_y)
OPTIONAL_NUMBER_ARG(center_y_ratio, 0.5f)
CALL_FUNCTION_NO_RET(SetScrollFromPosY, pos_y, center_y_ratio)
END_IMGUI_FUNC
//    IMGUI_API void          SetKeyboardFocusHere(int offset = 0);                               // focus keyboard on the next widget. Use positive 'offset' to access sub components of a multiple component widget. Use negative 'offset' to access previous widgets.
IMGUI_FUNCTION(SetKeyboardFocusHere)
OPTIONAL_INT_ARG(offset, 0)
CALL_FUNCTION_NO_RET(SetKeyboardFocusHere, offset)
END_IMGUI_FUNC
//    IMGUI_API void          SetStateStorage(ImGuiStorage* tree);                                // replace tree state storage with our own (if you want to manipulate it yourself, typically clear subsection of it)
// Unsupported arg type ImGuiStorage* tree
//    IMGUI_API ImGuiStorage* GetStateStorage();
// Unsupported return type ImGuiStorage*
//    IMGUI_API void          PushFont(ImFont* font);                                             // use NULL as a shortcut to push default font
// Unsupported arg type ImFont* font
//    IMGUI_API void          PopFont();
IMGUI_FUNCTION(PopFont)
CALL_FUNCTION_NO_RET(PopFont)
END_IMGUI_FUNC
//    IMGUI_API void          PushStyleColor(ImGuiCol idx, const ImVec4& col);
IMGUI_FUNCTION(PushStyleColor)
ENUM_ARG(idx)
IM_VEC_4_ARG(col)
CALL_FUNCTION_NO_RET(PushStyleColor, idx, col)
END_IMGUI_FUNC
//    IMGUI_API void          PopStyleColor(int count = 1);
IMGUI_FUNCTION(PopStyleColor)
OPTIONAL_INT_ARG(count, 1)
CALL_FUNCTION_NO_RET(PopStyleColor, count)
END_IMGUI_FUNC
//    IMGUI_API void          PushStyleVar(ImGuiStyleVar idx, float val);
IMGUI_FUNCTION(PushStyleVar)
ENUM_ARG(idx)
NUMBER_ARG(val)
CALL_FUNCTION_NO_RET(PushStyleVar, idx, val)
END_IMGUI_FUNC
//    IMGUI_API void          PushStyleVar(ImGuiStyleVar idx, const ImVec2& val);
IMGUI_FUNCTION(PushStyleVar_2)
ENUM_ARG(idx)
IM_VEC_2_ARG(val)
CALL_FUNCTION_NO_RET(PushStyleVar, idx, val)
END_IMGUI_FUNC
//    IMGUI_API void          PopStyleVar(int count = 1);
IMGUI_FUNCTION(PopStyleVar)
OPTIONAL_INT_ARG(count, 1)
CALL_FUNCTION_NO_RET(PopStyleVar, count)
END_IMGUI_FUNC
//    IMGUI_API ImFont*       GetFont();                                                          // get current font
// Unsupported return type ImFont*
//    IMGUI_API float         GetFontSize();                                                      // get current font size (= height in pixels) of current font with current scale applied
IMGUI_FUNCTION(GetFontSize)
CALL_FUNCTION(GetFontSize, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetFontTexUvWhitePixel();                                           // get UV coordinate for a while pixel, useful to draw custom shapes via the ImDrawList API
IMGUI_FUNCTION(GetFontTexUvWhitePixel)
CALL_FUNCTION(GetFontTexUvWhitePixel, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImU32         GetColorU32(ImGuiCol idx, float alpha_mul = 1.0f);                  // retrieve given style color with style alpha applied and optional extra alpha multiplier
//Not allowed to use this function
//    IMGUI_API ImU32         GetColorU32(const ImVec4& col);                                     // retrieve given color with style alpha applied
//Not allowed to use this function
//    IMGUI_API void          PushItemWidth(float item_width);                                    // width of items for the common item+label case, pixels. 0.0f = default to ~2/3 of windows width, >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side)
IMGUI_FUNCTION(PushItemWidth)
NUMBER_ARG(item_width)
CALL_FUNCTION_NO_RET(PushItemWidth, item_width)
END_IMGUI_FUNC
//    IMGUI_API void          PopItemWidth();
IMGUI_FUNCTION(PopItemWidth)
CALL_FUNCTION_NO_RET(PopItemWidth)
END_IMGUI_FUNC
//    IMGUI_API float         CalcItemWidth();                                                    // width of item given pushed settings and current cursor position
IMGUI_FUNCTION(CalcItemWidth)
CALL_FUNCTION(CalcItemWidth, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          PushTextWrapPos(float wrap_pos_x = 0.0f);                           // word-wrapping for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space
IMGUI_FUNCTION(PushTextWrapPos)
OPTIONAL_NUMBER_ARG(wrap_pos_x, 0.0f)
CALL_FUNCTION_NO_RET(PushTextWrapPos, wrap_pos_x)
END_IMGUI_FUNC
//    IMGUI_API void          PopTextWrapPos();
IMGUI_FUNCTION(PopTextWrapPos)
CALL_FUNCTION_NO_RET(PopTextWrapPos)
END_IMGUI_FUNC
//    IMGUI_API void          PushAllowKeyboardFocus(bool v);                                     // allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets
IMGUI_FUNCTION(PushAllowKeyboardFocus)
BOOL_ARG(v)
CALL_FUNCTION_NO_RET(PushAllowKeyboardFocus, v)
END_IMGUI_FUNC
//    IMGUI_API void          PopAllowKeyboardFocus();
IMGUI_FUNCTION(PopAllowKeyboardFocus)
CALL_FUNCTION_NO_RET(PopAllowKeyboardFocus)
END_IMGUI_FUNC
//    IMGUI_API void          PushButtonRepeat(bool repeat);                                      // in 'repeat' mode, Button*() functions return repeated true in a typematic manner (uses io.KeyRepeatDelay/io.KeyRepeatRate for now). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame.
IMGUI_FUNCTION(PushButtonRepeat)
BOOL_ARG(repeat)
CALL_FUNCTION_NO_RET(PushButtonRepeat, repeat)
END_IMGUI_FUNC
//    IMGUI_API void          PopButtonRepeat();
IMGUI_FUNCTION(PopButtonRepeat)
CALL_FUNCTION_NO_RET(PopButtonRepeat)
END_IMGUI_FUNC
//    IMGUI_API void          Separator();                                                        // horizontal line
IMGUI_FUNCTION(Separator)
CALL_FUNCTION_NO_RET(Separator)
END_IMGUI_FUNC
//    IMGUI_API void          SameLine(float pos_x = 0.0f, float spacing_w = -1.0f);              // call between widgets or groups to layout them horizontally
IMGUI_FUNCTION(SameLine)
OPTIONAL_NUMBER_ARG(pos_x, 0.0f)
OPTIONAL_NUMBER_ARG(spacing_w, -1.0f)
CALL_FUNCTION_NO_RET(SameLine, pos_x, spacing_w)
END_IMGUI_FUNC
//    IMGUI_API void          NewLine();                                                          // undo a SameLine()
IMGUI_FUNCTION(NewLine)
CALL_FUNCTION_NO_RET(NewLine)
END_IMGUI_FUNC
//    IMGUI_API void          Spacing();                                                          // add vertical spacing
IMGUI_FUNCTION(Spacing)
CALL_FUNCTION_NO_RET(Spacing)
END_IMGUI_FUNC
//    IMGUI_API void          Dummy(const ImVec2& size);                                          // add a dummy item of given size
IMGUI_FUNCTION(Dummy)
IM_VEC_2_ARG(size)
CALL_FUNCTION_NO_RET(Dummy, size)
END_IMGUI_FUNC
//    IMGUI_API void          Indent(float indent_w = 0.0f);                                      // move content position toward the right, by style.IndentSpacing or indent_w if >0
IMGUI_FUNCTION(Indent)
OPTIONAL_NUMBER_ARG(indent_w, 0.0f)
CALL_FUNCTION_NO_RET(Indent, indent_w)
END_IMGUI_FUNC
//    IMGUI_API void          Unindent(float indent_w = 0.0f);                                    // move content position back to the left, by style.IndentSpacing or indent_w if >0
IMGUI_FUNCTION(Unindent)
OPTIONAL_NUMBER_ARG(indent_w, 0.0f)
CALL_FUNCTION_NO_RET(Unindent, indent_w)
END_IMGUI_FUNC
//    IMGUI_API void          BeginGroup();                                                       // lock horizontal starting position + capture group bounding box into one "item" (so you can use IsItemHovered() or layout primitives such as SameLine() on whole group, etc.)
IMGUI_FUNCTION(BeginGroup)
CALL_FUNCTION_NO_RET(BeginGroup)
ADD_END_STACK(2)
END_IMGUI_FUNC
//    IMGUI_API void          EndGroup();
IMGUI_FUNCTION(EndGroup)
CALL_FUNCTION_NO_RET(EndGroup)
POP_END_STACK(2)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetCursorPos();                                                     // cursor position is relative to window position
IMGUI_FUNCTION(GetCursorPos)
CALL_FUNCTION(GetCursorPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API float         GetCursorPosX();                                                    // "
IMGUI_FUNCTION(GetCursorPosX)
CALL_FUNCTION(GetCursorPosX, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetCursorPosY();                                                    // "
IMGUI_FUNCTION(GetCursorPosY)
CALL_FUNCTION(GetCursorPosY, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          SetCursorPos(const ImVec2& local_pos);                              // "
IMGUI_FUNCTION(SetCursorPos)
IM_VEC_2_ARG(local_pos)
CALL_FUNCTION_NO_RET(SetCursorPos, local_pos)
END_IMGUI_FUNC
//    IMGUI_API void          SetCursorPosX(float x);                                             // "
IMGUI_FUNCTION(SetCursorPosX)
NUMBER_ARG(x)
CALL_FUNCTION_NO_RET(SetCursorPosX, x)
END_IMGUI_FUNC
//    IMGUI_API void          SetCursorPosY(float y);                                             // "
IMGUI_FUNCTION(SetCursorPosY)
NUMBER_ARG(y)
CALL_FUNCTION_NO_RET(SetCursorPosY, y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetCursorStartPos();                                                // initial cursor position
IMGUI_FUNCTION(GetCursorStartPos)
CALL_FUNCTION(GetCursorStartPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetCursorScreenPos();                                               // cursor position in absolute screen coordinates [0..io.DisplaySize] (useful to work with ImDrawList API)
IMGUI_FUNCTION(GetCursorScreenPos)
CALL_FUNCTION(GetCursorScreenPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API void          SetCursorScreenPos(const ImVec2& pos);                              // cursor position in absolute screen coordinates [0..io.DisplaySize]
IMGUI_FUNCTION(SetCursorScreenPos)
IM_VEC_2_ARG(pos)
CALL_FUNCTION_NO_RET(SetCursorScreenPos, pos)
END_IMGUI_FUNC
//    IMGUI_API void          AlignFirstTextHeightToWidgets();                                    // call once if the first item on the line is a Text() item and you want to vertically lower it to match subsequent (bigger) widgets
IMGUI_FUNCTION(AlignFirstTextHeightToWidgets)
CALL_FUNCTION_NO_RET(AlignFirstTextHeightToWidgets)
END_IMGUI_FUNC
//    IMGUI_API float         GetTextLineHeight();                                                // height of font == GetWindowFontSize()
IMGUI_FUNCTION(GetTextLineHeight)
CALL_FUNCTION(GetTextLineHeight, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetTextLineHeightWithSpacing();                                     // distance (in pixels) between 2 consecutive lines of text == GetWindowFontSize() + GetStyle().ItemSpacing.y
IMGUI_FUNCTION(GetTextLineHeightWithSpacing)
CALL_FUNCTION(GetTextLineHeightWithSpacing, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetItemsLineHeightWithSpacing();                                    // distance (in pixels) between 2 consecutive lines of standard height widgets == GetWindowFontSize() + GetStyle().FramePadding.y*2 + GetStyle().ItemSpacing.y
IMGUI_FUNCTION(GetItemsLineHeightWithSpacing)
CALL_FUNCTION(GetItemsLineHeightWithSpacing, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          Columns(int count = 1, const char* id = NULL, bool border = true);  // setup number of columns. use an identifier to distinguish multiple column sets. close with Columns(1).
IMGUI_FUNCTION(Columns)
OPTIONAL_INT_ARG(count, 1)
OPTIONAL_LABEL_ARG(id, NULL)
OPTIONAL_BOOL_ARG(border, true)
CALL_FUNCTION_NO_RET(Columns, count, id, border)
END_IMGUI_FUNC
//    IMGUI_API void          NextColumn();                                                       // next column
IMGUI_FUNCTION(NextColumn)
CALL_FUNCTION_NO_RET(NextColumn)
END_IMGUI_FUNC
//    IMGUI_API int           GetColumnIndex();                                                   // get current column index
IMGUI_FUNCTION(GetColumnIndex)
CALL_FUNCTION(GetColumnIndex, int)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetColumnOffset(int column_index = -1);                             // get position of column line (in pixels, from the left side of the contents region). pass -1 to use current column, otherwise 0..GetcolumnsCount() inclusive. column 0 is usually 0.0f and not resizable unless you call this
IMGUI_FUNCTION(GetColumnOffset)
OPTIONAL_INT_ARG(column_index, -1)
CALL_FUNCTION(GetColumnOffset, float, column_index)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          SetColumnOffset(int column_index, float offset_x);                  // set position of column line (in pixels, from the left side of the contents region). pass -1 to use current column
IMGUI_FUNCTION(SetColumnOffset)
INT_ARG(column_index)
NUMBER_ARG(offset_x)
CALL_FUNCTION_NO_RET(SetColumnOffset, column_index, offset_x)
END_IMGUI_FUNC
//    IMGUI_API float         GetColumnWidth(int column_index = -1);                              // column width (== GetColumnOffset(GetColumnIndex()+1) - GetColumnOffset(GetColumnOffset())
IMGUI_FUNCTION(GetColumnWidth)
OPTIONAL_INT_ARG(column_index, -1)
CALL_FUNCTION(GetColumnWidth, float, column_index)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API int           GetColumnsCount();                                                  // number of columns (what was passed to Columns())
IMGUI_FUNCTION(GetColumnsCount)
CALL_FUNCTION(GetColumnsCount, int)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          PushID(const char* str_id);                                         // push identifier into the ID stack. IDs are hash of the *entire* stack!
IMGUI_FUNCTION(PushID)
LABEL_ARG(str_id)
CALL_FUNCTION_NO_RET(PushID, str_id)
END_IMGUI_FUNC
//    IMGUI_API void          PushID(const char* str_id_begin, const char* str_id_end);
IMGUI_FUNCTION(PushID_2)
LABEL_ARG(str_id_begin)
LABEL_ARG(str_id_end)
CALL_FUNCTION_NO_RET(PushID, str_id_begin, str_id_end)
END_IMGUI_FUNC
//    IMGUI_API void          PushID(const void* ptr_id);
// Unsupported arg type const void* ptr_id
//    IMGUI_API void          PushID(int int_id);
IMGUI_FUNCTION(PushID_4)
INT_ARG(int_id)
CALL_FUNCTION_NO_RET(PushID, int_id)
END_IMGUI_FUNC
//    IMGUI_API void          PopID();
IMGUI_FUNCTION(PopID)
CALL_FUNCTION_NO_RET(PopID)
END_IMGUI_FUNC
//    IMGUI_API ImGuiID       GetID(const char* str_id);                                          // calculate unique ID (hash of whole ID stack + given parameter). useful if you want to query into ImGuiStorage yourself. otherwise rarely needed
IMGUI_FUNCTION(GetID)
LABEL_ARG(str_id)
CALL_FUNCTION(GetID, unsigned int, str_id)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API ImGuiID       GetID(const char* str_id_begin, const char* str_id_end);
IMGUI_FUNCTION(GetID_2)
LABEL_ARG(str_id_begin)
LABEL_ARG(str_id_end)
CALL_FUNCTION(GetID, unsigned int, str_id_begin, str_id_end)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API ImGuiID       GetID(const void* ptr_id);
// Unsupported arg type const void* ptr_id
//    IMGUI_API void          Text(const char* fmt, ...);
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(Text)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(Text, "%s", fmt)
END_IMGUI_FUNC
//    IMGUI_API void          TextV(const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API void          TextColored(const ImVec4& col, const char* fmt, ...);  // shortcut for PushStyleColor(ImGuiCol_Text, col); Text(fmt, ...); PopStyleColor();
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TextColored)
IM_VEC_4_ARG(col)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(TextColored, col, "%s", fmt)
END_IMGUI_FUNC
//    IMGUI_API void          TextColoredV(const ImVec4& col, const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API void          TextDisabled(const char* fmt, ...);                    // shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(fmt, ...); PopStyleColor();
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TextDisabled)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(TextDisabled, "%s", fmt)
END_IMGUI_FUNC
//    IMGUI_API void          TextDisabledV(const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API void          TextWrapped(const char* fmt, ...);                     // shortcut for PushTextWrapPos(0.0f); Text(fmt, ...); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize().
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TextWrapped)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(TextWrapped, "%s", fmt)
END_IMGUI_FUNC
//    IMGUI_API void          TextWrappedV(const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API void          TextUnformatted(const char* text, const char* text_end = NULL);         // doesn't require null terminated string if 'text_end' is specified. no copy done to any bounded stack buffer, recommended for long chunks of text
IMGUI_FUNCTION(TextUnformatted)
LABEL_ARG(text)
OPTIONAL_LABEL_ARG(text_end, NULL)
CALL_FUNCTION_NO_RET(TextUnformatted, text, text_end)
END_IMGUI_FUNC
//    IMGUI_API void          LabelText(const char* label, const char* fmt, ...);    // display text+label aligned the same way as value+label widgets
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(LabelText)
LABEL_ARG(label)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(LabelText, label, "%s", fmt)
END_IMGUI_FUNC
//    IMGUI_API void          LabelTextV(const char* label, const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API void          Bullet();                                                               // draw a small circle and keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses
IMGUI_FUNCTION(Bullet)
CALL_FUNCTION_NO_RET(Bullet)
END_IMGUI_FUNC
//    IMGUI_API void          BulletText(const char* fmt, ...);                      // shortcut for Bullet()+Text()
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(BulletText)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(BulletText, "%s", fmt)
END_IMGUI_FUNC
//    IMGUI_API void          BulletTextV(const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API bool          Button(const char* label, const ImVec2& size = ImVec2 0 0);            // button
IMGUI_FUNCTION(Button)
LABEL_ARG(label)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(Button, bool, label, size)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          SmallButton(const char* label);                                         // button with FramePadding=(0,0)
IMGUI_FUNCTION(SmallButton)
LABEL_ARG(label)
CALL_FUNCTION(SmallButton, bool, label)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          InvisibleButton(const char* str_id, const ImVec2& size);
IMGUI_FUNCTION(InvisibleButton)
LABEL_ARG(str_id)
IM_VEC_2_ARG(size)
CALL_FUNCTION(InvisibleButton, bool, str_id, size)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          Image(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2 0 0, const ImVec2& uv1 = ImVec2 1 1, const ImVec4& tint_col = ImVec4 1 1 1 1, const ImVec4& border_col = ImVec4 0 0 0 0);
IMGUI_FUNCTION(Image)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(size)
OPTIONAL_IM_VEC_2_ARG(uv0, 0, 0)
OPTIONAL_IM_VEC_2_ARG(uv1, 1, 1)
OPTIONAL_IM_VEC_4_ARG(tint_col, 1, 1, 1, 1)
OPTIONAL_IM_VEC_4_ARG(border_col, 0, 0, 0, 0)
CALL_FUNCTION_NO_RET(Image, user_texture_id, size, uv0, uv1, tint_col, border_col)
END_IMGUI_FUNC
//    IMGUI_API bool          ImageButton(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2 0 0,  const ImVec2& uv1 = ImVec2 1 1, int frame_padding = -1, const ImVec4& bg_col = ImVec4 0 0 0 0, const ImVec4& tint_col = ImVec4 1 1 1 1);    // <0 frame_padding uses default frame padding settings. 0 for no padding
IMGUI_FUNCTION(ImageButton)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(size)
OPTIONAL_IM_VEC_2_ARG(uv0, 0, 0)
OPTIONAL_IM_VEC_2_ARG(uv1, 1, 1)
OPTIONAL_INT_ARG(frame_padding, -1)
OPTIONAL_IM_VEC_4_ARG(bg_col, 0, 0, 0, 0)
OPTIONAL_IM_VEC_4_ARG(tint_col, 1, 1, 1, 1)
CALL_FUNCTION(ImageButton, bool, user_texture_id, size, uv0, uv1, frame_padding, bg_col, tint_col)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          Checkbox(const char* label, bool* v);
IMGUI_FUNCTION(Checkbox)
LABEL_ARG(label)
BOOL_POINTER_ARG(v)
CALL_FUNCTION(Checkbox, bool, label, v)
PUSH_BOOL(ret)
END_BOOL_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value);
IMGUI_FUNCTION(CheckboxFlags)
LABEL_ARG(label)
UINT_POINTER_ARG(flags)
UINT_ARG(flags_value)
CALL_FUNCTION(CheckboxFlags, bool, label, flags, flags_value)
PUSH_BOOL(ret)
END_UINT_POINTER(flags)
END_IMGUI_FUNC
//    IMGUI_API bool          RadioButton(const char* label, bool active);
IMGUI_FUNCTION(RadioButton)
LABEL_ARG(label)
BOOL_ARG(active)
CALL_FUNCTION(RadioButton, bool, label, active)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          RadioButton(const char* label, int* v, int v_button);
IMGUI_FUNCTION(RadioButton_2)
LABEL_ARG(label)
INT_POINTER_ARG(v)
INT_ARG(v_button)
CALL_FUNCTION(RadioButton, bool, label, v, v_button)
PUSH_BOOL(ret)
END_INT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          Combo(const char* label, int* current_item, const char** items, int items_count, int height_in_items = -1);
IMGUI_FUNCTION(Combo)
LABEL_ARG(label)
INT_CURRENT_ITEM_POINTER_ARG(current_item)
LABEL_ARRAY_ARG(items)
INT_ARG(items_count)
OPTIONAL_INT_ARG(height_in_items, -1)
CALL_FUNCTION(Combo, bool, label, current_item, items, items_count, height_in_items)
PUSH_BOOL(ret)
END_INT_CURRENT_ITEM_POINTER(current_item)
END_IMGUI_FUNC
//    IMGUI_API bool          Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int height_in_items = -1);      // separate items with \0, end item-list with \0\0
IMGUI_FUNCTION(Combo_2)
LABEL_ARG(label)
INT_CURRENT_ITEM_POINTER_ARG(current_item)
LABEL_ARG(items_separated_by_zeros)
OPTIONAL_INT_ARG(height_in_items, -1)
CALL_FUNCTION(Combo, bool, label, current_item, items_separated_by_zeros, height_in_items)
PUSH_BOOL(ret)
END_INT_CURRENT_ITEM_POINTER(current_item)
END_IMGUI_FUNC
//    IMGUI_API bool          Combo(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items = -1);
// Unsupported arg type  bool (*items_getter)(void* data
// Unsupported arg type  void* data
//    IMGUI_API bool          ColorButton(const ImVec4& col, bool small_height = false, bool outline_border = true);
IMGUI_FUNCTION(ColorButton)
IM_VEC_4_ARG(col)
OPTIONAL_BOOL_ARG(small_height, false)
OPTIONAL_BOOL_ARG(outline_border, true)
CALL_FUNCTION(ColorButton, bool, col, small_height, outline_border)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          ColorEdit3(const char* label, float col[3]);                            // Hint: 'float col[3]' function argument is same as 'float* col'. You can pass address of first element out of a contiguous set, e.g. &myvector.x
IMGUI_FUNCTION(ColorEdit3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(col)
CALL_FUNCTION(ColorEdit3, bool, label, col)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(col)
END_IMGUI_FUNC
//    IMGUI_API bool          ColorEdit4(const char* label, float col[4], bool show_alpha = true);    // "
IMGUI_FUNCTION(ColorEdit4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(col)
OPTIONAL_BOOL_ARG(show_alpha, true)
CALL_FUNCTION(ColorEdit4, bool, label, col, show_alpha)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(col)
END_IMGUI_FUNC
//    IMGUI_API void          ColorEditMode(ImGuiColorEditMode mode);                                 // FIXME-OBSOLETE: This is inconsistent with most of the API and will be obsoleted/replaced.
IMGUI_FUNCTION(ColorEditMode)
ENUM_ARG(mode)
CALL_FUNCTION_NO_RET(ColorEditMode, mode)
END_IMGUI_FUNC
//    IMGUI_API void          PlotLines(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0 0, int stride = sizeof(float));
IMGUI_FUNCTION(PlotLines)
LABEL_ARG(label)
FLOAT_ARRAY_ARG(values)
INT_ARG(values_count)
OPTIONAL_INT_ARG(values_offset, 0)
OPTIONAL_LABEL_ARG(overlay_text, NULL)
OPTIONAL_NUMBER_ARG(scale_min, FLT_MAX)
OPTIONAL_NUMBER_ARG(scale_max, FLT_MAX)
OPTIONAL_IM_VEC_2_ARG(graph_size, 0, 0)
OPTIONAL_INT_ARG(stride, sizeof(float))
CALL_FUNCTION_NO_RET(PlotLines, label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size, stride)
END_IMGUI_FUNC
//    IMGUI_API void          PlotLines(const char* label, float (*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0 0);
// Unsupported arg type  float (*values_getter)(void* data
// Unsupported arg type  void* data
//    IMGUI_API void          PlotHistogram(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0 0, int stride = sizeof(float));
IMGUI_FUNCTION(PlotHistogram)
LABEL_ARG(label)
FLOAT_ARRAY_ARG(values)
INT_ARG(values_count)
OPTIONAL_INT_ARG(values_offset, 0)
OPTIONAL_LABEL_ARG(overlay_text, NULL)
OPTIONAL_NUMBER_ARG(scale_min, FLT_MAX)
OPTIONAL_NUMBER_ARG(scale_max, FLT_MAX)
OPTIONAL_IM_VEC_2_ARG(graph_size, 0, 0)
OPTIONAL_INT_ARG(stride, sizeof(float))
CALL_FUNCTION_NO_RET(PlotHistogram, label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size, stride)
END_IMGUI_FUNC
//    IMGUI_API void          PlotHistogram(const char* label, float (*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0 0);
// Unsupported arg type  float (*values_getter)(void* data
// Unsupported arg type  void* data
//    IMGUI_API void          ProgressBar(float fraction, const ImVec2& size_arg = ImVec2 -1 0, const char* overlay = NULL);
IMGUI_FUNCTION(ProgressBar)
NUMBER_ARG(fraction)
OPTIONAL_IM_VEC_2_ARG(size_arg, -1, 0)
OPTIONAL_LABEL_ARG(overlay, NULL)
CALL_FUNCTION_NO_RET(ProgressBar, fraction, size_arg, overlay)
END_IMGUI_FUNC
//    IMGUI_API bool          DragFloat(const char* label, float* v, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* display_format = "%.3f", float power = 1.0f);     // If v_min >= v_max we have no bound
IMGUI_FUNCTION(DragFloat)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat, bool, label, v, v_speed, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragFloat2(const char* label, float v[2], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(DragFloat2)
LABEL_ARG(label)
FLOAT_ARRAY2_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat2, bool, label, v, v_speed, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY2(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragFloat3(const char* label, float v[3], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(DragFloat3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat3, bool, label, v, v_speed, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragFloat4(const char* label, float v[4], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(DragFloat4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat4, bool, label, v, v_speed, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragFloatRange2(const char* label, float* v_current_min, float* v_current_max, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* display_format = "%.3f", const char* display_format_max = NULL, float power = 1.0f);
IMGUI_FUNCTION(DragFloatRange2)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v_current_min)
FLOAT_POINTER_ARG(v_current_max)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_LABEL_ARG(display_format_max, NULL)
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloatRange2, bool, label, v_current_min, v_current_max, v_speed, v_min, v_max, display_format, display_format_max, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v_current_min)
END_FLOAT_POINTER(v_current_max)
END_IMGUI_FUNC
//    IMGUI_API bool          DragInt(const char* label, int* v, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* display_format = "%.0f");                                       // If v_min >= v_max we have no bound
IMGUI_FUNCTION(DragInt)
LABEL_ARG(label)
INT_POINTER_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(DragInt, bool, label, v, v_speed, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragInt2(const char* label, int v[2], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* display_format = "%.0f");
IMGUI_FUNCTION(DragInt2)
LABEL_ARG(label)
INT_ARRAY2_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(DragInt2, bool, label, v, v_speed, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_ARRAY2(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragInt3(const char* label, int v[3], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* display_format = "%.0f");
IMGUI_FUNCTION(DragInt3)
LABEL_ARG(label)
INT_ARRAY3_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(DragInt3, bool, label, v, v_speed, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_ARRAY3(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragInt4(const char* label, int v[4], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* display_format = "%.0f");
IMGUI_FUNCTION(DragInt4)
LABEL_ARG(label)
INT_ARRAY4_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(DragInt4, bool, label, v, v_speed, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_ARRAY4(v)
END_IMGUI_FUNC
//    IMGUI_API bool          DragIntRange2(const char* label, int* v_current_min, int* v_current_max, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* display_format = "%.0f", const char* display_format_max = NULL);
IMGUI_FUNCTION(DragIntRange2)
LABEL_ARG(label)
INT_POINTER_ARG(v_current_min)
INT_POINTER_ARG(v_current_max)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
OPTIONAL_LABEL_ARG(display_format_max, NULL)
CALL_FUNCTION(DragIntRange2, bool, label, v_current_min, v_current_max, v_speed, v_min, v_max, display_format, display_format_max)
PUSH_BOOL(ret)
END_INT_POINTER(v_current_min)
END_INT_POINTER(v_current_max)
END_IMGUI_FUNC
//    IMGUI_API bool          InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiTextEditCallback callback = NULL, void* user_data = NULL);
IMGUI_FUNCTION(InputText)
LABEL_ARG(label)
LABEL_POINTER_ARG(buf)
OPTIONAL_ENUM_ARG(flags, 0)
DEFAULT_ARG(ImGuiTextEditCallback, callback, NULL)
DEFAULT_ARG(void*, user_data, NULL)
CALL_FUNCTION(InputText, bool, label, buf, buf_size, flags, callback, user_data)
PUSH_BOOL(ret)
END_LABEL_POINTER(buf)
END_IMGUI_FUNC
//    IMGUI_API bool          InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2 0 0, ImGuiInputTextFlags flags = 0, ImGuiTextEditCallback callback = NULL, void* user_data = NULL);
IMGUI_FUNCTION(InputTextMultiline)
LABEL_ARG(label)
LABEL_POINTER_ARG(buf)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
OPTIONAL_ENUM_ARG(flags, 0)
DEFAULT_ARG(ImGuiTextEditCallback, callback, NULL)
DEFAULT_ARG(void*, user_data, NULL)
CALL_FUNCTION(InputTextMultiline, bool, label, buf, buf_size, size, flags, callback, user_data)
PUSH_BOOL(ret)
END_LABEL_POINTER(buf)
END_IMGUI_FUNC
//    IMGUI_API bool          InputFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, int decimal_precision = -1, ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputFloat)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v)
OPTIONAL_NUMBER_ARG(step, 0.0f)
OPTIONAL_NUMBER_ARG(step_fast, 0.0f)
OPTIONAL_INT_ARG(decimal_precision, -1)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputFloat, bool, label, v, step, step_fast, decimal_precision, extra_flags)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputFloat2(const char* label, float v[2], int decimal_precision = -1, ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputFloat2)
LABEL_ARG(label)
FLOAT_ARRAY2_ARG(v)
OPTIONAL_INT_ARG(decimal_precision, -1)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputFloat2, bool, label, v, decimal_precision, extra_flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY2(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputFloat3(const char* label, float v[3], int decimal_precision = -1, ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputFloat3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(v)
OPTIONAL_INT_ARG(decimal_precision, -1)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputFloat3, bool, label, v, decimal_precision, extra_flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputFloat4(const char* label, float v[4], int decimal_precision = -1, ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputFloat4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(v)
OPTIONAL_INT_ARG(decimal_precision, -1)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputFloat4, bool, label, v, decimal_precision, extra_flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputInt)
LABEL_ARG(label)
INT_POINTER_ARG(v)
OPTIONAL_INT_ARG(step, 1)
OPTIONAL_INT_ARG(step_fast, 100)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputInt, bool, label, v, step, step_fast, extra_flags)
PUSH_BOOL(ret)
END_INT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputInt2(const char* label, int v[2], ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputInt2)
LABEL_ARG(label)
INT_ARRAY2_ARG(v)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputInt2, bool, label, v, extra_flags)
PUSH_BOOL(ret)
END_INT_ARRAY2(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputInt3(const char* label, int v[3], ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputInt3)
LABEL_ARG(label)
INT_ARRAY3_ARG(v)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputInt3, bool, label, v, extra_flags)
PUSH_BOOL(ret)
END_INT_ARRAY3(v)
END_IMGUI_FUNC
//    IMGUI_API bool          InputInt4(const char* label, int v[4], ImGuiInputTextFlags extra_flags = 0);
IMGUI_FUNCTION(InputInt4)
LABEL_ARG(label)
INT_ARRAY4_ARG(v)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(InputInt4, bool, label, v, extra_flags)
PUSH_BOOL(ret)
END_INT_ARRAY4(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderFloat(const char* label, float* v, float v_min, float v_max, const char* display_format = "%.3f", float power = 1.0f);     // adjust display_format to decorate the value with a prefix or a suffix. Use power!=1.0 for logarithmic sliders
IMGUI_FUNCTION(SliderFloat)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat, bool, label, v, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(SliderFloat2)
LABEL_ARG(label)
FLOAT_ARRAY2_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat2, bool, label, v, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY2(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(SliderFloat3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat3, bool, label, v, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(SliderFloat4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat4, bool, label, v, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderAngle(const char* label, float* v_rad, float v_degrees_min = -360.0f, float v_degrees_max = +360.0f);
IMGUI_FUNCTION(SliderAngle)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v_rad)
OPTIONAL_NUMBER_ARG(v_degrees_min, -360.0f)
OPTIONAL_NUMBER_ARG(v_degrees_max, +360.0f)
CALL_FUNCTION(SliderAngle, bool, label, v_rad, v_degrees_min, v_degrees_max)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v_rad)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderInt(const char* label, int* v, int v_min, int v_max, const char* display_format = "%.0f");
IMGUI_FUNCTION(SliderInt)
LABEL_ARG(label)
INT_POINTER_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(SliderInt, bool, label, v, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* display_format = "%.0f");
IMGUI_FUNCTION(SliderInt2)
LABEL_ARG(label)
INT_ARRAY2_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(SliderInt2, bool, label, v, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_ARRAY2(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* display_format = "%.0f");
IMGUI_FUNCTION(SliderInt3)
LABEL_ARG(label)
INT_ARRAY3_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(SliderInt3, bool, label, v, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_ARRAY3(v)
END_IMGUI_FUNC
//    IMGUI_API bool          SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* display_format = "%.0f");
IMGUI_FUNCTION(SliderInt4)
LABEL_ARG(label)
INT_ARRAY4_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(SliderInt4, bool, label, v, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_ARRAY4(v)
END_IMGUI_FUNC
//    IMGUI_API bool          VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* display_format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(VSliderFloat)
LABEL_ARG(label)
IM_VEC_2_ARG(size)
FLOAT_POINTER_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(VSliderFloat, bool, label, size, v, v_min, v_max, display_format, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* display_format = "%.0f");
IMGUI_FUNCTION(VSliderInt)
LABEL_ARG(label)
IM_VEC_2_ARG(size)
INT_POINTER_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(display_format, "%.0f")
CALL_FUNCTION(VSliderInt, bool, label, size, v, v_min, v_max, display_format)
PUSH_BOOL(ret)
END_INT_POINTER(v)
END_IMGUI_FUNC
//    IMGUI_API bool          TreeNode(const char* label);                                            // if returning 'true' the node is open and the tree id is pushed into the id stack. user is responsible for calling TreePop().
IMGUI_FUNCTION(TreeNode)
LABEL_ARG(label)
CALL_FUNCTION(TreeNode, bool, label)
IF_RET_ADD_END_STACK(3)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          TreeNode(const char* str_id, const char* fmt, ...);    // read the FAQ about why and how to use ID. to align arbitrary text at the same level as a TreeNode() you can use Bullet().
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TreeNode_2)
LABEL_ARG(str_id)
LABEL_ARG(fmt)
CALL_FUNCTION(TreeNode, bool, str_id, fmt)
IF_RET_ADD_END_STACK(3)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          TreeNode(const void* ptr_id, const char* fmt, ...);    // "
// Unsupported arg type const void* ptr_id
// Variadic functions aren't suppported but here it is anyway
//    IMGUI_API bool          TreeNodeV(const char* str_id, const char* fmt, va_list args);           // "
// Unsupported arg type  va_list args
//    IMGUI_API bool          TreeNodeV(const void* ptr_id, const char* fmt, va_list args);           // "
// Unsupported arg type const void* ptr_id
// Unsupported arg type  va_list args
//    IMGUI_API bool          TreeNodeEx(const char* label, ImGuiTreeNodeFlags flags = 0);
IMGUI_FUNCTION(TreeNodeEx)
LABEL_ARG(label)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(TreeNodeEx, bool, label, flags)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          TreeNodeEx(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, ...);
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TreeNodeEx_2)
LABEL_ARG(str_id)
ENUM_ARG(flags)
LABEL_ARG(fmt)
CALL_FUNCTION(TreeNodeEx, bool, str_id, flags, fmt)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          TreeNodeEx(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...);
// Unsupported arg type const void* ptr_id
// Variadic functions aren't suppported but here it is anyway
//    IMGUI_API bool          TreeNodeExV(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API bool          TreeNodeExV(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args);
// Unsupported arg type const void* ptr_id
// Unsupported arg type  va_list args
//    IMGUI_API void          TreePush(const char* str_id = NULL);                                    // ~ Indent()+PushId(). Already called by TreeNode() when returning true, but you can call Push/Pop yourself for layout purpose
IMGUI_FUNCTION(TreePush)
OPTIONAL_LABEL_ARG(str_id, NULL)
CALL_FUNCTION_NO_RET(TreePush, str_id)
ADD_END_STACK(3)
END_IMGUI_FUNC
//    IMGUI_API void          TreePush(const void* ptr_id = NULL);                                    // "
IMGUI_FUNCTION(TreePush_2)
DEFAULT_ARG(const void*, ptr_id, NULL)
CALL_FUNCTION_NO_RET(TreePush, ptr_id)
ADD_END_STACK(3)
END_IMGUI_FUNC
//    IMGUI_API void          TreePop();                                                              // ~ Unindent()+PopId()
IMGUI_FUNCTION(TreePop)
CALL_FUNCTION_NO_RET(TreePop)
POP_END_STACK(3)
END_IMGUI_FUNC
//    IMGUI_API void          TreeAdvanceToLabelPos();                                                // advance cursor x position by GetTreeNodeToLabelSpacing()
IMGUI_FUNCTION(TreeAdvanceToLabelPos)
CALL_FUNCTION_NO_RET(TreeAdvanceToLabelPos)
END_IMGUI_FUNC
//    IMGUI_API float         GetTreeNodeToLabelSpacing();                                            // horizontal distance preceeding label when using TreeNode*() or Bullet() == (g.FontSize + style.FramePadding.x*2) for a regular unframed TreeNode
IMGUI_FUNCTION(GetTreeNodeToLabelSpacing)
CALL_FUNCTION(GetTreeNodeToLabelSpacing, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          SetNextTreeNodeOpen(bool is_open, ImGuiSetCond cond = 0);               // set next TreeNode/CollapsingHeader open state.
IMGUI_FUNCTION(SetNextTreeNodeOpen)
BOOL_ARG(is_open)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextTreeNodeOpen, is_open, cond)
END_IMGUI_FUNC
//    IMGUI_API bool          CollapsingHeader(const char* label, ImGuiTreeNodeFlags flags = 0);      // if returning 'true' the header is open. doesn't indent nor push on ID stack. user doesn't have to call TreePop().
IMGUI_FUNCTION(CollapsingHeader)
LABEL_ARG(label)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(CollapsingHeader, bool, label, flags)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          CollapsingHeader(const char* label, bool* p_open, ImGuiTreeNodeFlags flags = 0); // when 'p_open' isn't NULL, display an additional small close button on upper right of the header
IMGUI_FUNCTION(CollapsingHeader_2)
LABEL_ARG(label)
BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(CollapsingHeader, bool, label, p_open, flags)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC
//    IMGUI_API bool          Selectable(const char* label, bool selected = false, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2 0 0);  // size.x==0.0: use remaining width, size.x>0.0: specify width. size.y==0.0: use label height, size.y>0.0: specify height
IMGUI_FUNCTION(Selectable)
LABEL_ARG(label)
OPTIONAL_BOOL_ARG(selected, false)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(Selectable, bool, label, selected, flags, size)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          Selectable(const char* label, bool* p_selected, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2 0 0);
IMGUI_FUNCTION(Selectable_2)
LABEL_ARG(label)
BOOL_POINTER_ARG(p_selected)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(Selectable, bool, label, p_selected, flags, size)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_selected)
END_IMGUI_FUNC
//    IMGUI_API bool          ListBox(const char* label, int* current_item, const char** items, int items_count, int height_in_items = -1);
IMGUI_FUNCTION(ListBox)
LABEL_ARG(label)
INT_CURRENT_ITEM_POINTER_ARG(current_item)
LABEL_ARRAY_ARG(items)
INT_ARG(items_count)
OPTIONAL_INT_ARG(height_in_items, -1)
CALL_FUNCTION(ListBox, bool, label, current_item, items, items_count, height_in_items)
PUSH_BOOL(ret)
END_INT_CURRENT_ITEM_POINTER(current_item)
END_IMGUI_FUNC
//    IMGUI_API bool          ListBox(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items = -1);
// Unsupported arg type  bool (*items_getter)(void* data
// Unsupported arg type  void* data
//    IMGUI_API bool          ListBoxHeader(const char* label, const ImVec2& size = ImVec2 0 0); // use if you want to reimplement ListBox() will custom data or interactions. make sure to call ListBoxFooter() afterwards.
IMGUI_FUNCTION(ListBoxHeader)
LABEL_ARG(label)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(ListBoxHeader, bool, label, size)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          ListBoxHeader(const char* label, int items_count, int height_in_items = -1); // "
IMGUI_FUNCTION(ListBoxHeader_2)
LABEL_ARG(label)
INT_ARG(items_count)
OPTIONAL_INT_ARG(height_in_items, -1)
CALL_FUNCTION(ListBoxHeader, bool, label, items_count, height_in_items)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          ListBoxFooter();                                                    // terminate the scrolling region
IMGUI_FUNCTION(ListBoxFooter)
CALL_FUNCTION_NO_RET(ListBoxFooter)
END_IMGUI_FUNC
//    IMGUI_API void          Value(const char* prefix, bool b);
IMGUI_FUNCTION(Value)
LABEL_ARG(prefix)
BOOL_ARG(b)
CALL_FUNCTION_NO_RET(Value, prefix, b)
END_IMGUI_FUNC
//    IMGUI_API void          Value(const char* prefix, int v);
IMGUI_FUNCTION(Value_2)
LABEL_ARG(prefix)
INT_ARG(v)
CALL_FUNCTION_NO_RET(Value, prefix, v)
END_IMGUI_FUNC
//    IMGUI_API void          Value(const char* prefix, unsigned int v);
IMGUI_FUNCTION(Value_3)
LABEL_ARG(prefix)
UINT_ARG(v)
CALL_FUNCTION_NO_RET(Value, prefix, v)
END_IMGUI_FUNC
//    IMGUI_API void          Value(const char* prefix, float v, const char* float_format = NULL);
IMGUI_FUNCTION(Value_4)
LABEL_ARG(prefix)
NUMBER_ARG(v)
OPTIONAL_LABEL_ARG(float_format, NULL)
CALL_FUNCTION_NO_RET(Value, prefix, v, float_format)
END_IMGUI_FUNC
//    IMGUI_API void          ValueColor(const char* prefix, const ImVec4& v);
IMGUI_FUNCTION(ValueColor)
LABEL_ARG(prefix)
IM_VEC_4_ARG(v)
CALL_FUNCTION_NO_RET(ValueColor, prefix, v)
END_IMGUI_FUNC
//    IMGUI_API void          ValueColor(const char* prefix, ImU32 v);
IMGUI_FUNCTION(ValueColor_2)
LABEL_ARG(prefix)
UINT_ARG(v)
CALL_FUNCTION_NO_RET(ValueColor, prefix, v)
END_IMGUI_FUNC
//    IMGUI_API void          SetTooltip(const char* fmt, ...);                  // set tooltip under mouse-cursor, typically use with ImGui::IsHovered(). last call wins
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(SetTooltip)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(SetTooltip, fmt)
END_IMGUI_FUNC
//    IMGUI_API void          SetTooltipV(const char* fmt, va_list args);
// Unsupported arg type  va_list args
//    IMGUI_API void          BeginTooltip();                                                     // use to create full-featured tooltip windows that aren't just text
IMGUI_FUNCTION(BeginTooltip)
CALL_FUNCTION_NO_RET(BeginTooltip)
ADD_END_STACK(4)
END_IMGUI_FUNC
//    IMGUI_API void          EndTooltip();
IMGUI_FUNCTION(EndTooltip)
CALL_FUNCTION_NO_RET(EndTooltip)
POP_END_STACK(4)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginMainMenuBar();                                                 // create and append to a full screen menu-bar. only call EndMainMenuBar() if this returns true!
IMGUI_FUNCTION(BeginMainMenuBar)
CALL_FUNCTION(BeginMainMenuBar, bool)
IF_RET_ADD_END_STACK(5)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          EndMainMenuBar();
IMGUI_FUNCTION(EndMainMenuBar)
CALL_FUNCTION_NO_RET(EndMainMenuBar)
POP_END_STACK(5)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginMenuBar();                                                     // append to menu-bar of current window (requires ImGuiWindowFlags_MenuBar flag set). only call EndMenuBar() if this returns true!
IMGUI_FUNCTION(BeginMenuBar)
CALL_FUNCTION(BeginMenuBar, bool)
IF_RET_ADD_END_STACK(6)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          EndMenuBar();
IMGUI_FUNCTION(EndMenuBar)
CALL_FUNCTION_NO_RET(EndMenuBar)
POP_END_STACK(6)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginMenu(const char* label, bool enabled = true);                  // create a sub-menu entry. only call EndMenu() if this returns true!
IMGUI_FUNCTION(BeginMenu)
LABEL_ARG(label)
OPTIONAL_BOOL_ARG(enabled, true)
CALL_FUNCTION(BeginMenu, bool, label, enabled)
IF_RET_ADD_END_STACK(7)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          EndMenu();
IMGUI_FUNCTION(EndMenu)
CALL_FUNCTION_NO_RET(EndMenu)
POP_END_STACK(7)
END_IMGUI_FUNC
//    IMGUI_API bool          MenuItem(const char* label, const char* shortcut = NULL, bool selected = false, bool enabled = true);  // return true when activated. shortcuts are displayed for convenience but not processed by ImGui at the moment
IMGUI_FUNCTION(MenuItem)
LABEL_ARG(label)
OPTIONAL_LABEL_ARG(shortcut, NULL)
OPTIONAL_BOOL_ARG(selected, false)
OPTIONAL_BOOL_ARG(enabled, true)
CALL_FUNCTION(MenuItem, bool, label, shortcut, selected, enabled)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled = true);              // return true when activated + toggle (*p_selected) if p_selected != NULL
IMGUI_FUNCTION(MenuItem_2)
LABEL_ARG(label)
LABEL_ARG(shortcut)
BOOL_POINTER_ARG(p_selected)
OPTIONAL_BOOL_ARG(enabled, true)
CALL_FUNCTION(MenuItem, bool, label, shortcut, p_selected, enabled)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_selected)
END_IMGUI_FUNC
//    IMGUI_API void          OpenPopup(const char* str_id);                                      // mark popup as open. popups are closed when user click outside, or activate a pressable item, or CloseCurrentPopup() is called within a BeginPopup()/EndPopup() block. popup identifiers are relative to the current ID-stack (so OpenPopup and BeginPopup needs to be at the same level).
IMGUI_FUNCTION(OpenPopup)
LABEL_ARG(str_id)
CALL_FUNCTION_NO_RET(OpenPopup, str_id)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginPopup(const char* str_id);                                     // return true if the popup is open, and you can start outputting to it. only call EndPopup() if BeginPopup() returned true!
IMGUI_FUNCTION(BeginPopup)
LABEL_ARG(str_id)
CALL_FUNCTION(BeginPopup, bool, str_id)
IF_RET_ADD_END_STACK(8)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginPopupModal(const char* name, bool* p_open = NULL, ImGuiWindowFlags extra_flags = 0);               // modal dialog (can't close them by clicking outside)
IMGUI_FUNCTION(BeginPopupModal)
LABEL_ARG(name)
OPTIONAL_BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(BeginPopupModal, bool, name, p_open, extra_flags)
IF_RET_ADD_END_STACK(8)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginPopupContextItem(const char* str_id, int mouse_button = 1);                                        // helper to open and begin popup when clicked on last item. read comments in .cpp!
IMGUI_FUNCTION(BeginPopupContextItem)
LABEL_ARG(str_id)
OPTIONAL_INT_ARG(mouse_button, 1)
CALL_FUNCTION(BeginPopupContextItem, bool, str_id, mouse_button)
IF_RET_ADD_END_STACK(8)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginPopupContextWindow(bool also_over_items = true, const char* str_id = NULL, int mouse_button = 1);  // helper to open and begin popup when clicked on current window.
IMGUI_FUNCTION(BeginPopupContextWindow)
OPTIONAL_BOOL_ARG(also_over_items, true)
OPTIONAL_LABEL_ARG(str_id, NULL)
OPTIONAL_INT_ARG(mouse_button, 1)
CALL_FUNCTION(BeginPopupContextWindow, bool, also_over_items, str_id, mouse_button)
IF_RET_ADD_END_STACK(8)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginPopupContextVoid(const char* str_id = NULL, int mouse_button = 1);                                 // helper to open and begin popup when clicked in void (no window).
IMGUI_FUNCTION(BeginPopupContextVoid)
OPTIONAL_LABEL_ARG(str_id, NULL)
OPTIONAL_INT_ARG(mouse_button, 1)
CALL_FUNCTION(BeginPopupContextVoid, bool, str_id, mouse_button)
IF_RET_ADD_END_STACK(8)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          EndPopup();
IMGUI_FUNCTION(EndPopup)
CALL_FUNCTION_NO_RET(EndPopup)
POP_END_STACK(8)
END_IMGUI_FUNC
//    IMGUI_API void          CloseCurrentPopup();                                                // close the popup we have begin-ed into. clicking on a MenuItem or Selectable automatically close the current popup.
IMGUI_FUNCTION(CloseCurrentPopup)
CALL_FUNCTION_NO_RET(CloseCurrentPopup)
END_IMGUI_FUNC
//    IMGUI_API void          LogToTTY(int max_depth = -1);                                       // start logging to tty
IMGUI_FUNCTION(LogToTTY)
OPTIONAL_INT_ARG(max_depth, -1)
CALL_FUNCTION_NO_RET(LogToTTY, max_depth)
END_IMGUI_FUNC
//    IMGUI_API void          LogToFile(int max_depth = -1, const char* filename = NULL);         // start logging to file
IMGUI_FUNCTION(LogToFile)
OPTIONAL_INT_ARG(max_depth, -1)
OPTIONAL_LABEL_ARG(filename, NULL)
CALL_FUNCTION_NO_RET(LogToFile, max_depth, filename)
END_IMGUI_FUNC
//    IMGUI_API void          LogToClipboard(int max_depth = -1);                                 // start logging to OS clipboard
IMGUI_FUNCTION(LogToClipboard)
OPTIONAL_INT_ARG(max_depth, -1)
CALL_FUNCTION_NO_RET(LogToClipboard, max_depth)
END_IMGUI_FUNC
//    IMGUI_API void          LogFinish();                                                        // stop logging (close file, etc.)
IMGUI_FUNCTION(LogFinish)
CALL_FUNCTION_NO_RET(LogFinish)
END_IMGUI_FUNC
//    IMGUI_API void          LogButtons();                                                       // helper to display buttons for logging to tty/file/clipboard
IMGUI_FUNCTION(LogButtons)
CALL_FUNCTION_NO_RET(LogButtons)
END_IMGUI_FUNC
//    IMGUI_API void          LogText(const char* fmt, ...);                     // pass text data straight to log (without being displayed)
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(LogText)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(LogText, fmt)
END_IMGUI_FUNC
//    IMGUI_API void          PushClipRect(const ImVec2& clip_rect_min, const ImVec2& clip_rect_max, bool intersect_with_current_clip_rect);
IMGUI_FUNCTION(PushClipRect)
IM_VEC_2_ARG(clip_rect_min)
IM_VEC_2_ARG(clip_rect_max)
BOOL_ARG(intersect_with_current_clip_rect)
CALL_FUNCTION_NO_RET(PushClipRect, clip_rect_min, clip_rect_max, intersect_with_current_clip_rect)
END_IMGUI_FUNC
//    IMGUI_API void          PopClipRect();
IMGUI_FUNCTION(PopClipRect)
CALL_FUNCTION_NO_RET(PopClipRect)
END_IMGUI_FUNC
//    IMGUI_API bool          IsItemHovered();                                                    // was the last item hovered by mouse?
IMGUI_FUNCTION(IsItemHovered)
CALL_FUNCTION(IsItemHovered, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsItemHoveredRect();                                                // was the last item hovered by mouse? even if another item is active or window is blocked by popup while we are hovering this
IMGUI_FUNCTION(IsItemHoveredRect)
CALL_FUNCTION(IsItemHoveredRect, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsItemActive();                                                     // was the last item active? (e.g. button being held, text field being edited- items that don't interact will always return false)
IMGUI_FUNCTION(IsItemActive)
CALL_FUNCTION(IsItemActive, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsItemClicked(int mouse_button = 0);                                // was the last item clicked? (e.g. button/node just clicked on)
IMGUI_FUNCTION(IsItemClicked)
OPTIONAL_INT_ARG(mouse_button, 0)
CALL_FUNCTION(IsItemClicked, bool, mouse_button)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsItemVisible();                                                    // was the last item visible? (aka not out of sight due to clipping/scrolling.)
IMGUI_FUNCTION(IsItemVisible)
CALL_FUNCTION(IsItemVisible, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsAnyItemHovered();
IMGUI_FUNCTION(IsAnyItemHovered)
CALL_FUNCTION(IsAnyItemHovered, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsAnyItemActive();
IMGUI_FUNCTION(IsAnyItemActive)
CALL_FUNCTION(IsAnyItemActive, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetItemRectMin();                                                   // get bounding rect of last item in screen space
IMGUI_FUNCTION(GetItemRectMin)
CALL_FUNCTION(GetItemRectMin, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetItemRectMax();                                                   // "
IMGUI_FUNCTION(GetItemRectMax)
CALL_FUNCTION(GetItemRectMax, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetItemRectSize();                                                  // "
IMGUI_FUNCTION(GetItemRectSize)
CALL_FUNCTION(GetItemRectSize, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API void          SetItemAllowOverlap();                                              // allow last item to be overlapped by a subsequent item. sometimes useful with invisible buttons, selectables, etc. to catch unused area.
IMGUI_FUNCTION(SetItemAllowOverlap)
CALL_FUNCTION_NO_RET(SetItemAllowOverlap)
END_IMGUI_FUNC
//    IMGUI_API bool          IsWindowHovered();                                                  // is current window hovered and hoverable (not blocked by a popup) (differentiate child windows from each others)
IMGUI_FUNCTION(IsWindowHovered)
CALL_FUNCTION(IsWindowHovered, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsWindowFocused();                                                  // is current window focused
IMGUI_FUNCTION(IsWindowFocused)
CALL_FUNCTION(IsWindowFocused, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsRootWindowFocused();                                              // is current root window focused (root = top-most parent of a child, otherwise self)
IMGUI_FUNCTION(IsRootWindowFocused)
CALL_FUNCTION(IsRootWindowFocused, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsRootWindowOrAnyChildFocused();                                    // is current root window or any of its child (including current window) focused
IMGUI_FUNCTION(IsRootWindowOrAnyChildFocused)
CALL_FUNCTION(IsRootWindowOrAnyChildFocused, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsRootWindowOrAnyChildHovered();                                    // is current root window or any of its child (including current window) hovered and hoverable (not blocked by a popup)
IMGUI_FUNCTION(IsRootWindowOrAnyChildHovered)
CALL_FUNCTION(IsRootWindowOrAnyChildHovered, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsRectVisible(const ImVec2& size);                                  // test if rectangle of given size starting from cursor pos is visible (not clipped). to perform coarse clipping on user's side (as an optimization)
IMGUI_FUNCTION(IsRectVisible)
IM_VEC_2_ARG(size)
CALL_FUNCTION(IsRectVisible, bool, size)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsPosHoveringAnyWindow(const ImVec2& pos);                          // is given position hovering any active imgui window
IMGUI_FUNCTION(IsPosHoveringAnyWindow)
IM_VEC_2_ARG(pos)
CALL_FUNCTION(IsPosHoveringAnyWindow, bool, pos)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API float         GetTime();
IMGUI_FUNCTION(GetTime)
CALL_FUNCTION(GetTime, float)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API int           GetFrameCount();
IMGUI_FUNCTION(GetFrameCount)
CALL_FUNCTION(GetFrameCount, int)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API const char*   GetStyleColName(ImGuiCol idx);
IMGUI_FUNCTION(GetStyleColName)
ENUM_ARG(idx)
CALL_FUNCTION(GetStyleColName, const char*, idx)
PUSH_STRING(ret)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        CalcItemRectClosestPoint(const ImVec2& pos, bool on_edge = false, float outward = +0.0f);   // utility to find the closest point the last item bounding rectangle edge. useful to visually link items
IMGUI_FUNCTION(CalcItemRectClosestPoint)
IM_VEC_2_ARG(pos)
OPTIONAL_BOOL_ARG(on_edge, false)
OPTIONAL_NUMBER_ARG(outward, +0.0f)
CALL_FUNCTION(CalcItemRectClosestPoint, ImVec2, pos, on_edge, outward)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        CalcTextSize(const char* text, const char* text_end = NULL, bool hide_text_after_double_hash = false, float wrap_width = -1.0f);
IMGUI_FUNCTION(CalcTextSize)
LABEL_ARG(text)
OPTIONAL_LABEL_ARG(text_end, NULL)
OPTIONAL_BOOL_ARG(hide_text_after_double_hash, false)
OPTIONAL_NUMBER_ARG(wrap_width, -1.0f)
CALL_FUNCTION(CalcTextSize, ImVec2, text, text_end, hide_text_after_double_hash, wrap_width)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API void          CalcListClipping(int items_count, float items_height, int* out_items_display_start, int* out_items_display_end);    // calculate coarse clipping for large list of evenly sized items. Prefer using the ImGuiListClipper higher-level helper if you can.
IMGUI_FUNCTION(CalcListClipping)
INT_ARG(items_count)
NUMBER_ARG(items_height)
INT_POINTER_ARG(out_items_display_start)
INT_POINTER_ARG(out_items_display_end)
CALL_FUNCTION_NO_RET(CalcListClipping, items_count, items_height, out_items_display_start, out_items_display_end)
END_INT_POINTER(out_items_display_start)
END_INT_POINTER(out_items_display_end)
END_IMGUI_FUNC
//    IMGUI_API bool          BeginChildFrame(ImGuiID id, const ImVec2& size, ImGuiWindowFlags extra_flags = 0);	// helper to create a child window / scrolling region that looks like a normal widget frame
IMGUI_FUNCTION(BeginChildFrame)
UINT_ARG(id)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(BeginChildFrame, bool, id, size, extra_flags)
IF_RET_ADD_END_STACK(9)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API void          EndChildFrame();
IMGUI_FUNCTION(EndChildFrame)
CALL_FUNCTION_NO_RET(EndChildFrame)
POP_END_STACK(9)
END_IMGUI_FUNC
//    IMGUI_API ImVec4        ColorConvertU32ToFloat4(ImU32 in);
IMGUI_FUNCTION(ColorConvertU32ToFloat4)
UINT_ARG(in)
CALL_FUNCTION(ColorConvertU32ToFloat4, ImVec4, in)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_NUMBER(ret.z)
PUSH_NUMBER(ret.w)
END_IMGUI_FUNC
//    IMGUI_API ImU32         ColorConvertFloat4ToU32(const ImVec4& in);
IMGUI_FUNCTION(ColorConvertFloat4ToU32)
IM_VEC_4_ARG(in)
CALL_FUNCTION(ColorConvertFloat4ToU32, unsigned int, in)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API void          ColorConvertRGBtoHSV(float r, float g, float b, float& out_h, float& out_s, float& out_v);
// Unsupported arg type  float& out_h
// Unsupported arg type  float& out_s
// Unsupported arg type  float& out_v
//    IMGUI_API void          ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b);
// Unsupported arg type  float& out_r
// Unsupported arg type  float& out_g
// Unsupported arg type  float& out_b
//    IMGUI_API int           GetKeyIndex(ImGuiKey key);                                          // map ImGuiKey_* values into user's key index. == io.KeyMap[key]
IMGUI_FUNCTION(GetKeyIndex)
ENUM_ARG(key)
CALL_FUNCTION(GetKeyIndex, int, key)
PUSH_NUMBER(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsKeyDown(int key_index);                                           // key_index into the keys_down[] array, imgui doesn't know the semantic of each entry, uses your own indices!
IMGUI_FUNCTION(IsKeyDown)
INT_ARG(key_index)
CALL_FUNCTION(IsKeyDown, bool, key_index)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsKeyPressed(int key_index, bool repeat = true);                    // uses user's key indices as stored in the keys_down[] array. if repeat=true. uses io.KeyRepeatDelay / KeyRepeatRate
IMGUI_FUNCTION(IsKeyPressed)
INT_ARG(key_index)
OPTIONAL_BOOL_ARG(repeat, true)
CALL_FUNCTION(IsKeyPressed, bool, key_index, repeat)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsKeyReleased(int key_index);                                       // "
IMGUI_FUNCTION(IsKeyReleased)
INT_ARG(key_index)
CALL_FUNCTION(IsKeyReleased, bool, key_index)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseDown(int button);                                            // is mouse button held
IMGUI_FUNCTION(IsMouseDown)
INT_ARG(button)
CALL_FUNCTION(IsMouseDown, bool, button)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseClicked(int button, bool repeat = false);                    // did mouse button clicked (went from !Down to Down)
IMGUI_FUNCTION(IsMouseClicked)
INT_ARG(button)
OPTIONAL_BOOL_ARG(repeat, false)
CALL_FUNCTION(IsMouseClicked, bool, button, repeat)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseDoubleClicked(int button);                                   // did mouse button double-clicked. a double-click returns false in IsMouseClicked(). uses io.MouseDoubleClickTime.
IMGUI_FUNCTION(IsMouseDoubleClicked)
INT_ARG(button)
CALL_FUNCTION(IsMouseDoubleClicked, bool, button)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseReleased(int button);                                        // did mouse button released (went from Down to !Down)
IMGUI_FUNCTION(IsMouseReleased)
INT_ARG(button)
CALL_FUNCTION(IsMouseReleased, bool, button)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseHoveringWindow();                                            // is mouse hovering current window ("window" in API names always refer to current window). disregarding of any consideration of being blocked by a popup. (unlike IsWindowHovered() this will return true even if the window is blocked because of a popup)
IMGUI_FUNCTION(IsMouseHoveringWindow)
CALL_FUNCTION(IsMouseHoveringWindow, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseHoveringAnyWindow();                                         // is mouse hovering any visible window
IMGUI_FUNCTION(IsMouseHoveringAnyWindow)
CALL_FUNCTION(IsMouseHoveringAnyWindow, bool)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseHoveringRect(const ImVec2& r_min, const ImVec2& r_max, bool clip = true);  // is mouse hovering given bounding rect (in screen space). clipped by current clipping settings. disregarding of consideration of focus/window ordering/blocked by a popup.
IMGUI_FUNCTION(IsMouseHoveringRect)
IM_VEC_2_ARG(r_min)
IM_VEC_2_ARG(r_max)
OPTIONAL_BOOL_ARG(clip, true)
CALL_FUNCTION(IsMouseHoveringRect, bool, r_min, r_max, clip)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API bool          IsMouseDragging(int button = 0, float lock_threshold = -1.0f);      // is mouse dragging. if lock_threshold < -1.0f uses io.MouseDraggingThreshold
IMGUI_FUNCTION(IsMouseDragging)
OPTIONAL_INT_ARG(button, 0)
OPTIONAL_NUMBER_ARG(lock_threshold, -1.0f)
CALL_FUNCTION(IsMouseDragging, bool, button, lock_threshold)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetMousePos();                                                      // shortcut to ImGui::GetIO().MousePos provided by user, to be consistent with other calls
IMGUI_FUNCTION(GetMousePos)
CALL_FUNCTION(GetMousePos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetMousePosOnOpeningCurrentPopup();                                 // retrieve backup of mouse positioning at the time of opening popup we have BeginPopup() into
IMGUI_FUNCTION(GetMousePosOnOpeningCurrentPopup)
CALL_FUNCTION(GetMousePosOnOpeningCurrentPopup, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API ImVec2        GetMouseDragDelta(int button = 0, float lock_threshold = -1.0f);    // dragging amount since clicking. if lock_threshold < -1.0f uses io.MouseDraggingThreshold
IMGUI_FUNCTION(GetMouseDragDelta)
OPTIONAL_INT_ARG(button, 0)
OPTIONAL_NUMBER_ARG(lock_threshold, -1.0f)
CALL_FUNCTION(GetMouseDragDelta, ImVec2, button, lock_threshold)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
END_IMGUI_FUNC
//    IMGUI_API void          ResetMouseDragDelta(int button = 0);                                //
IMGUI_FUNCTION(ResetMouseDragDelta)
OPTIONAL_INT_ARG(button, 0)
CALL_FUNCTION_NO_RET(ResetMouseDragDelta, button)
END_IMGUI_FUNC
//    IMGUI_API ImGuiMouseCursor GetMouseCursor();                                                // get desired cursor type, reset in ImGui::NewFrame(), this updated during the frame. valid before Render(). If you use software rendering by setting io.MouseDrawCursor ImGui will render those for you
// Unsupported return type ImGuiMouseCursor
//    IMGUI_API void          SetMouseCursor(ImGuiMouseCursor type);                              // set desired cursor type
IMGUI_FUNCTION(SetMouseCursor)
ENUM_ARG(type)
CALL_FUNCTION_NO_RET(SetMouseCursor, type)
END_IMGUI_FUNC
//    IMGUI_API void          CaptureKeyboardFromApp(bool capture = true);                        // manually override io.WantCaptureKeyboard flag next frame (said flag is entirely left for your application handle). e.g. force capture keyboard when your widget is being hovered.
IMGUI_FUNCTION(CaptureKeyboardFromApp)
OPTIONAL_BOOL_ARG(capture, true)
CALL_FUNCTION_NO_RET(CaptureKeyboardFromApp, capture)
END_IMGUI_FUNC
//    IMGUI_API void          CaptureMouseFromApp(bool capture = true);                           // manually override io.WantCaptureMouse flag next frame (said flag is entirely left for your application handle).
IMGUI_FUNCTION(CaptureMouseFromApp)
OPTIONAL_BOOL_ARG(capture, true)
CALL_FUNCTION_NO_RET(CaptureMouseFromApp, capture)
END_IMGUI_FUNC
//    IMGUI_API void*         MemAlloc(size_t sz);
// Unsupported return type void*
// Unsupported arg type size_t sz
//    IMGUI_API void          MemFree(void* ptr);
// Unsupported arg type void* ptr
//    IMGUI_API const char*   GetClipboardText();
IMGUI_FUNCTION(GetClipboardText)
CALL_FUNCTION(GetClipboardText, const char*)
PUSH_STRING(ret)
END_IMGUI_FUNC
//    IMGUI_API void          SetClipboardText(const char* text);
IMGUI_FUNCTION(SetClipboardText)
LABEL_ARG(text)
CALL_FUNCTION_NO_RET(SetClipboardText, text)
END_IMGUI_FUNC
//    IMGUI_API const char*   GetVersion();
IMGUI_FUNCTION(GetVersion)
CALL_FUNCTION(GetVersion, const char*)
PUSH_STRING(ret)
END_IMGUI_FUNC

//IMGUI_API void  AddLine(const ImVec2 &a, const ImVec2 &b, ImU32 col, float thickness = 1.0f);
IMGUI_FUNCTION(AddLine)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
NUMBER_ARG(col)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
CALL_DRAWLIST_FUNCTION_NO_RET(AddLine, a, b, col, thickness)
END_IMGUI_FUNC

//IMGUI_API void  AddRect(const ImVec2 &a, const ImVec2 &b, ImU32 col, float rounding = 0.0f, int rounding_corners = 0x0F, float thickness = 1.0f);   // a: upper-left, b: lower-right
IMGUI_FUNCTION(AddRect)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
NUMBER_ARG(col)
OPTIONAL_NUMBER_ARG(rounding, 0.0f)
OPTIONAL_INT_ARG(rounding_corners, 0x0F)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
CALL_DRAWLIST_FUNCTION_NO_RET(AddRect, a, b, col, rounding, rounding_corners, thickness)
END_IMGUI_FUNC

//IMGUI_API void  AddRectFilled(const ImVec2 &a, const ImVec2 &b, ImU32 col, float rounding = 0.0f, int rounding_corners = 0x0F);                     // a: upper-left, b: lower-right
IMGUI_FUNCTION(AddRectFilled)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
NUMBER_ARG(col)
OPTIONAL_NUMBER_ARG(rounding, 0.0f)
OPTIONAL_INT_ARG(rounding_corners, 0x0F)
CALL_DRAWLIST_FUNCTION_NO_RET(AddRectFilled, a, b, col, rounding, rounding_corners)
END_IMGUI_FUNC

//IMGUI_API void  AddRectFilledMultiColor(const ImVec2 &a, const ImVec2 &b, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left);
IMGUI_FUNCTION(AddRectFilledMultiColor)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
NUMBER_ARG(colUL)
NUMBER_ARG(colUR)
NUMBER_ARG(colBR)
NUMBER_ARG(colBL)
CALL_DRAWLIST_FUNCTION_NO_RET(AddRectFilledMultiColor, a, b, colUL, colUR, colBR, colBL)
END_IMGUI_FUNC

//IMGUI_API void  AddQuad(const ImVec2 &a, const ImVec2 &b, const ImVec2 &c, const ImVec2 &d, ImU32 col, float thickness = 1.0f);
IMGUI_FUNCTION(AddQuad)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
IM_VEC_2_ARG(c)
IM_VEC_2_ARG(d)
NUMBER_ARG(col)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
CALL_DRAWLIST_FUNCTION_NO_RET(AddQuad, a, b, c, d, col, thickness)
END_IMGUI_FUNC

//IMGUI_API void  AddQuadFilled(const ImVec2 &a, const ImVec2 &b, const ImVec2 &c, const ImVec2 &d, ImU32 col);
IMGUI_FUNCTION(AddQuadFilled)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
IM_VEC_2_ARG(c)
IM_VEC_2_ARG(d)
NUMBER_ARG(col)
CALL_DRAWLIST_FUNCTION_NO_RET(AddQuadFilled, a, b, c, d, col)
END_IMGUI_FUNC

//IMGUI_API void  AddTriangle(const ImVec2 &a, const ImVec2 &b, const ImVec2 &c, ImU32 col, float thickness = 1.0f);
IMGUI_FUNCTION(AddTriangle)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
IM_VEC_2_ARG(c)
NUMBER_ARG(col)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
CALL_DRAWLIST_FUNCTION_NO_RET(AddTriangle, a, b, c, col, thickness)
END_IMGUI_FUNC

//IMGUI_API void  AddTriangleFilled(const ImVec2 &a, const ImVec2 &b, const ImVec2 &c, ImU32 col);
IMGUI_FUNCTION(AddTriangleFilled)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
IM_VEC_2_ARG(c)
NUMBER_ARG(col)
CALL_DRAWLIST_FUNCTION_NO_RET(AddTriangleFilled, a, b, c, col)
END_IMGUI_FUNC

//IMGUI_API void  AddCircle(const ImVec2 &centre, float radius, ImU32 col, int num_segments = 12, float thickness = 1.0f);
IMGUI_FUNCTION(AddCircle)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
NUMBER_ARG(col)
OPTIONAL_INT_ARG(num_segments, 12)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
CALL_DRAWLIST_FUNCTION_NO_RET(AddCircle, center, radius, col, num_segments, thickness)
END_IMGUI_FUNC

//IMGUI_API void  AddCircleFilled(const ImVec2 &centre, float radius, ImU32 col, int num_segments = 12);
IMGUI_FUNCTION(AddCircleFilled)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
NUMBER_ARG(col)
OPTIONAL_INT_ARG(num_segments, 12)
CALL_DRAWLIST_FUNCTION_NO_RET(AddCircleFilled, center, radius, col, num_segments)
END_IMGUI_FUNC


//IMGUI_API void  AddBezierCurve(const ImVec2 &pos0, const ImVec2 &cp0, const ImVec2 &cp1, const ImVec2 &pos1, ImU32 col, float thickness, int num_segments = 0);
IMGUI_FUNCTION(AddBezierCurve)
IM_VEC_2_ARG(pos0)
IM_VEC_2_ARG(cp0)
IM_VEC_2_ARG(cp1)
IM_VEC_2_ARG(pos1)
NUMBER_ARG(col)
NUMBER_ARG(thickness)
OPTIONAL_INT_ARG(num_segments, 0)
CALL_DRAWLIST_FUNCTION_NO_RET(AddBezierCurve, pos0, cp0, cp1, pos1, col, thickness, num_segments)
END_IMGUI_FUNC

// TODO...
// How to handle texture?
//IMGUI_API void  AddImage(ImTextureID user_texture_id, const ImVec2 &a, const ImVec2 &b, const ImVec2 &uv0 = ImVec2(0, 0), const ImVec2 &uv1 = ImVec2(1, 1), ImU32 col = 0xFFFFFFFF);

// How to pass and retrieve a table for the first argument?
// Probably easier to just make wrappers for these in the pso table.
//IMGUI_API void  AddPolyline(const ImVec2 *points, const int num_points, ImU32 col, bool closed, float thickness, bool anti_aliased);
//IMGUI_API void  AddConvexPolyFilled(const ImVec2 *points, const int num_points, ImU32 col, bool anti_aliased);



//    IMGUI_API ImGuiContext* CreateContext(void* (*malloc_fn)(size_t) = NULL, void (*free_fn)(void*) = NULL);
// Unsupported return type ImGuiContext*
//    IMGUI_API void          DestroyContext(ImGuiContext* ctx);
// Unsupported arg type ImGuiContext* ctx
//    IMGUI_API ImGuiContext* GetCurrentContext();
// Unsupported return type ImGuiContext*
//    IMGUI_API void          SetCurrentContext(ImGuiContext* ctx);
// Unsupported arg type ImGuiContext* ctx
END_STACK_START
END_STACK_OPTION(0, End)
END_STACK_OPTION(1, EndChild)
END_STACK_OPTION(2, EndGroup)
END_STACK_OPTION(3, TreePop)
END_STACK_OPTION(4, EndTooltip)
END_STACK_OPTION(5, EndMainMenuBar)
END_STACK_OPTION(6, EndMenuBar)
END_STACK_OPTION(7, EndMenu)
END_STACK_OPTION(8, EndPopup)
END_STACK_OPTION(9, EndChildFrame)
END_STACK_END
