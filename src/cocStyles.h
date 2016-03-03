#pragma once

#include "CinderImGui.h"

namespace coc {

static ImGuiStyle getStyleDefault()
{
	ImGuiStyle style;

	style.WindowMinSize            = ImVec2( 160, 20 );
	style.FramePadding             = ImVec2( 4, 2 );
	style.ItemSpacing              = ImVec2( 6, 2 );
	style.ItemInnerSpacing         = ImVec2( 6, 4 );
	style.Alpha					   = 0.95f;
	style.WindowFillAlphaDefault   = 1.0f;
	style.WindowRounding           = 4.0f;
	style.FrameRounding            = 2.0f;
	style.IndentSpacing            = 6.0f;
	style.ItemInnerSpacing		   = ImVec2( 2, 4 );
	style.ColumnsMinSpacing        = 50.0f;
	style.GrabMinSize			   = 14.0f;
	style.GrabRounding			   = 16.0f;
	style.ScrollbarSize			   = 12.0f;
	style.ScrollbarRounding		   = 16.0f;

	style.Colors[ImGuiCol_Text]                  = ImVec4(0.86f, 0.93f, 0.89f, 0.61f);
	style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
	style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.20f, 0.22f, 0.27f, 0.58f);
	style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
	style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.47f, 0.77f, 0.83f, 0.21f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Button]                = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Header]                = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
	style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Column]                = ImVec4(0.47f, 0.77f, 0.83f, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
	style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.86f, 0.93f, 0.89f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.86f, 0.93f, 0.89f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
	style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.92f, 0.18f, 0.29f, 0.43f);
	style.Colors[ImGuiCol_TooltipBg]             = ImVec4(0.47f, 0.77f, 0.83f, 0.72f);
	style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.20f, 0.22f, 0.27f, 0.73f);

	return style;

}

static ImGuiStyle getStyleDark()
{
	ImGuiStyle style;

	style.WindowPadding            = ImVec2( 20, 10 );
	style.WindowMinSize            = ImVec2( 160, 20 );
	style.FramePadding             = ImVec2( 4, 4 );
	style.ItemSpacing              = ImVec2( 8, 4 );
	style.ItemInnerSpacing         = ImVec2( 6, 4 );
	style.Alpha					   = 0.95f;
	style.WindowFillAlphaDefault   = 0.95f;
	style.WindowRounding           = 2.0f;
	style.FrameRounding            = 2.0f;
	style.IndentSpacing            = 6;
	style.ColumnsMinSpacing        = 50;
	//	style.ScrollbarWidth           = 12;
	style.ScrollbarSize			   = 12.0f;

	style.Colors[ImGuiCol_Text]                  = ImVec4(1.00f, 1.00f, 0.86f, 0.50f);
	style.Colors[ImGuiCol_TextDisabled]          = ImVec4(1.00f, 1.00f, 0.86f, 0.22f);
	style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.23f, 0.23f, 0.23f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.97f, 0.48f, 0.32f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.33f, 0.33f, 0.33f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.36f, 0.36f, 0.36f, 1.00f);
	style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.22f, 0.22f, 0.22f, 0.50f);
	style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.23f, 0.23f, 0.23f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_Button]                = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive]          = ImVec4(1.00f, 1.00f, 0.62f, 1.00f);
	style.Colors[ImGuiCol_Header]                = ImVec4(0.34f, 0.34f, 0.34f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_Column]                = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
	style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.68f, 0.68f, 0.68f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.65f, 0.65f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.71f, 0.71f, 0.71f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_TooltipBg]             = ImVec4(0.16f, 0.16f, 0.16f, 0.72f);
	style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.20f, 0.20f, 0.20f, 0.65f);

	return style;
}

// Flat UI Theme https://color.adobe.com/Flat-UI-color-theme-2469224
static ImGuiStyle getStyleFlat()
{
	ImGuiStyle style;

	style.WindowPadding = ImVec2( 20, 10 );
	style.WindowMinSize = ImVec2( 160, 20 );
	style.FramePadding = ImVec2( 4, 4 );
	style.ItemSpacing = ImVec2( 8, 4 );
	style.ItemInnerSpacing = ImVec2( 6, 4 );
	style.Alpha = 0.95f;
	style.WindowFillAlphaDefault = 0.95f;
	style.WindowRounding = 2.0f;
	style.FrameRounding = 2.0f;
	style.IndentSpacing = 6;
	style.ColumnsMinSpacing = 50;
	//	style.ScrollbarWidth           = 12;
	style.ScrollbarSize			   = 12.0f;

	//@formatter:off
	style.Colors[ImGuiCol_Text]                  = ImVec4(0.93f, 0.94f, 0.95f, 0.61f);
	style.Colors[ImGuiCol_TextDisabled]          = ImVec4(1.00f, 1.00f, 0.86f, 0.22f);
	style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.16f, 0.50f, 0.73f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.16f, 0.50f, 0.73f, 1.00f);
	style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.20f, 0.60f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.91f, 0.30f, 0.24f, 0.78f);
	style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.16f, 0.50f, 0.73f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.16f, 0.50f, 0.73f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.16f, 0.50f, 0.73f, 0.47f);
	style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.60f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.16f, 0.50f, 0.73f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.91f, 0.30f, 0.24f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.20f, 0.60f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.16f, 0.50f, 0.73f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.93f, 0.94f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_Button]                = ImVec4(0.91f, 0.30f, 0.24f, 0.76f);
	style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.91f, 0.30f, 0.24f, 0.86f);
	style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_Header]                = ImVec4(0.91f, 0.30f, 0.24f, 0.76f);
	style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.91f, 0.30f, 0.24f, 0.86f);
	style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_Column]                = ImVec4(0.17f, 0.24f, 0.31f, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.91f, 0.30f, 0.24f, 0.78f);
	style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.17f, 0.24f, 0.31f, 0.32f);
	style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.91f, 0.30f, 0.24f, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.93f, 0.94f, 0.95f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.93f, 0.94f, 0.95f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.93f, 0.94f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.93f, 0.94f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.93f, 0.94f, 0.95f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.91f, 0.30f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.91f, 0.30f, 0.31f, 1.00f);
	style.Colors[ImGuiCol_TooltipBg]             = ImVec4(0.17f, 0.24f, 0.31f, 0.72f);
	style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.17f, 0.24f, 0.31f, 0.65f);
	//@formatter:on

	return style;
}

//Sea Wolf https://color.adobe.com/Sea-Wolf-color-theme-782171
static ImGuiStyle getStyleSeaWolf()
{
	ImGuiStyle style;

	style.WindowMinSize            = ImVec2( 160, 20 );
	style.FramePadding             = ImVec2( 4, 2 );
	style.ItemSpacing              = ImVec2( 6, 2 );
	style.ItemInnerSpacing         = ImVec2( 6, 4 );
	style.Alpha					   = 0.95f;
	style.WindowFillAlphaDefault   = 1.0f;
	style.WindowRounding           = 4.0f;
	style.FrameRounding            = 2.0f;
	style.IndentSpacing            = 6.0f;
	style.ItemInnerSpacing		   = ImVec2( 2, 4 );
	style.ColumnsMinSpacing        = 50.0f;
	style.GrabMinSize			   = 14.0f;
	style.GrabRounding			   = 16.0f;
	style.ScrollbarSize			   = 12.0f;
	style.ScrollbarRounding		   = 16.0f;

	style.Colors[ImGuiCol_Text]                  = ImVec4(0.85f, 0.80f, 0.62f, 0.61f);
	style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.85f, 0.80f, 0.62f, 0.22f);
	style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.16f, 0.17f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.16f, 0.17f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.22f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.86f, 0.21f, 0.13f, 0.78f);
	style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.16f, 0.17f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.16f, 0.17f, 0.17f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.16f, 0.17f, 0.17f, 0.47f);
	style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.22f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.16f, 0.17f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.86f, 0.21f, 0.13f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.22f, 0.25f, 0.25f, 1.00f);
	style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.16f, 0.17f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.85f, 0.80f, 0.62f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_Button]                = ImVec4(0.86f, 0.21f, 0.13f, 0.76f);
	style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.86f, 0.21f, 0.13f, 0.86f);
	style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_Header]                = ImVec4(0.86f, 0.21f, 0.13f, 0.76f);
	style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.86f, 0.21f, 0.13f, 0.86f);
	style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_Column]                = ImVec4(0.12f, 0.12f, 0.13f, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.86f, 0.21f, 0.13f, 0.78f);
	style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.12f, 0.12f, 0.13f, 0.32f);
	style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.86f, 0.21f, 0.13f, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.85f, 0.80f, 0.62f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.85f, 0.80f, 0.62f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.85f, 0.80f, 0.62f, 1.00f);
	style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.85f, 0.80f, 0.62f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.85f, 0.80f, 0.62f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.86f, 0.21f, 0.13f, 1.00f);
	style.Colors[ImGuiCol_TooltipBg]             = ImVec4(0.12f, 0.12f, 0.13f, 0.72f);
	style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.12f, 0.12f, 0.13f, 0.65f);

	return style;


}

//https://color.adobe.com/Cinderella-from-Nam-color-theme-2071015/edit/?copy=true
static ImGuiStyle getStyleCinderella()
{
	ImGuiStyle style;

	style.WindowMinSize            = ImVec2( 160, 20 );
	style.FramePadding             = ImVec2( 4, 2 );
	style.ItemSpacing              = ImVec2( 6, 2 );
	style.ItemInnerSpacing         = ImVec2( 6, 4 );
	style.Alpha					   = 0.95f;
	style.WindowFillAlphaDefault   = 1.0f;
	style.WindowRounding           = 4.0f;
	style.FrameRounding            = 2.0f;
	style.IndentSpacing            = 6.0f;
	style.ItemInnerSpacing		   = ImVec2( 2, 4 );
	style.ColumnsMinSpacing        = 50.0f;
	style.GrabMinSize			   = 14.0f;
	style.GrabRounding			   = 16.0f;
	style.ScrollbarSize			   = 12.0f;
	style.ScrollbarRounding		   = 16.0f;

	style.Colors[ImGuiCol_Text]                  = ImVec4(0.95f, 0.90f, 0.64f, 0.61f);
	style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.95f, 0.90f, 0.64f, 0.22f);
	style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.26f, 0.35f, 0.34f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.26f, 0.35f, 0.34f, 1.00f);
	style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.51f, 0.67f, 0.55f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.85f, 0.40f, 0.40f, 0.78f);
	style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.26f, 0.35f, 0.34f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.26f, 0.35f, 0.34f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.26f, 0.35f, 0.34f, 0.47f);
	style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.51f, 0.67f, 0.55f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.26f, 0.35f, 0.34f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.85f, 0.40f, 0.40f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.51f, 0.67f, 0.55f, 1.00f);
	style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.26f, 0.35f, 0.34f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.95f, 0.90f, 0.64f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_Button]                = ImVec4(0.85f, 0.40f, 0.40f, 0.76f);
	style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.85f, 0.40f, 0.40f, 0.86f);
	style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_Header]                = ImVec4(0.85f, 0.40f, 0.40f, 0.76f);
	style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.85f, 0.40f, 0.40f, 0.86f);
	style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_Column]                = ImVec4(0.97f, 0.60f, 0.51f, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.85f, 0.40f, 0.40f, 0.78f);
	style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.97f, 0.60f, 0.51f, 0.32f);
	style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.85f, 0.40f, 0.40f, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.95f, 0.90f, 0.64f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.95f, 0.90f, 0.64f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.95f, 0.90f, 0.64f, 1.00f);
	style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.95f, 0.90f, 0.64f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.95f, 0.90f, 0.64f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.85f, 0.40f, 0.40f, 1.00f);
	style.Colors[ImGuiCol_TooltipBg]             = ImVec4(0.97f, 0.60f, 0.51f, 0.72f);
	style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.97f, 0.60f, 0.51f, 0.65f);

	return style;
}

//CS04 Theme https://color.adobe.com/CS04-color-theme-1994456
static ImGuiStyle getStyleCS04()
{
	ImGuiStyle style;

	style.WindowMinSize            = ImVec2( 160, 20 );
	style.FramePadding             = ImVec2( 4, 2 );
	style.ItemSpacing              = ImVec2( 6, 2 );
	style.ItemInnerSpacing         = ImVec2( 6, 4 );
	style.Alpha					   = 0.95f;
	style.WindowFillAlphaDefault   = 1.0f;
	style.WindowRounding           = 4.0f;
	style.FrameRounding            = 2.0f;
	style.IndentSpacing            = 6.0f;
	style.ItemInnerSpacing		   = ImVec2( 2, 4 );
	style.ColumnsMinSpacing        = 50.0f;
	style.GrabMinSize			   = 14.0f;
	style.GrabRounding			   = 16.0f;
	style.ScrollbarSize			   = 12.0f;
	style.ScrollbarRounding		   = 16.0f;

	style.Colors[ImGuiCol_Text]                  = ImVec4(0.86f, 0.93f, 0.89f, 0.61f);
	style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.86f, 0.93f, 0.89f, 0.22f);
	style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
	style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.47f, 0.77f, 0.83f, 0.44f);
	style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Button]                = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
	style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Header]                = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
	style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
	style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_Column]                = ImVec4(0.47f, 0.77f, 0.83f, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.47f, 0.77f, 0.83f, 0.32f);
	style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
	style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.86f, 0.93f, 0.89f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.86f, 0.93f, 0.89f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
	style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_TooltipBg]             = ImVec4(0.47f, 0.77f, 0.83f, 0.72f);
	style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.47f, 0.77f, 0.83f, 0.65f);

	return style;

}

} //namespace coc