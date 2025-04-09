// SandSmile By EnterCont
#define _USE_MATH_DEFINES 1
#include <cmath>
#include <cstdio>
#include <iostream>
#include <windows.h>
int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
		HDC hdc = GetDC(0);
		HDC desk;
		int sw = GetSystemMetrics(0);
		int sh = GetSystemMetrics(1);
		int x = GetSystemMetrics(0);
		int y = GetSystemMetrics(1);
		int w = GetSystemMetrics(0);
		int h = GetSystemMetrics(1);
		int signX = 1;
		int signY = 1;
		int signX1 = 1;
		int signY1 = 1;
		int incrementor = 10;
		int xbc = 10;
		int ybc = 10;

		for (int i = 400; i < 450; i++) {
			Beep(430, 80);
			hdc = GetDC(0);
			PatBlt(hdc, 0, 0, x, y, PATINVERT);
			Beep(130, 80);
			ReleaseDC(0, hdc);
			Beep(730, 80);
		}
		for (int i = 400; i < 450; i++) {
			Beep(730, 80);
			hdc = GetDC(0);
			Beep(530, 80);
			BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 2, rand() % 2, SRCAND);
			ReleaseDC(0, hdc);
			Beep(230, 80);
		}
		for (int i = 400; i < 450; i++) {
			Beep(330, 80);
			HDC hdc = GetDC(0);
			BitBlt(hdc, -30, 0, w, h, hdc, 0, 0, SRCCOPY);
			BitBlt(hdc, w - 30, 0, w, h, hdc, 0, 0, SRCCOPY);
			ReleaseDC(0, hdc);
			Beep(530, 80);
			Beep(230, 80);
		}
		for (int i = 1000800; i < 1000850; i++) {
			Beep(830, 80);
			HDC hdc = GetDC(0);
			xbc += incrementor * signX;
			ybc += incrementor * signY;
			int top_x = 0 + xbc;
			int top_y = 0 + ybc;
			int bottom_x = 100 + xbc;
			int bottom_y = 100 + ybc;
			HBRUSH brush = CreateSolidBrush(RGB(rand() % 555, rand() % 555, rand() % 255));
			SelectObject(hdc, brush);
			Ellipse(hdc, top_x, top_y, bottom_x, bottom_y);
			if (ybc >= GetSystemMetrics(SM_CYSCREEN))
			{
				signY = -1;
			}

			if (xbc >= GetSystemMetrics(SM_CXSCREEN))
			{
				signX = -1;
			}

			if (ybc == 0)
			{
				signY = 1;
			}

			if (xbc == 0)
			{
				signX = 1;
			}
			DeleteObject(brush);
			ReleaseDC(0, hdc);
		}
		for (int i = 400; i < 450; i++) {
			Beep(330, 30);
			HDC hdc = GetDC(0);
			POINT p[4] = { rand() % sw, rand() % sh, rand() % sw, rand() % sh,  rand() % sw, rand() % sh };
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
			SelectObject(hdc, hPen);
			PolyBezier(hdc, p, 4);
			DeleteObject(hPen);
			ReleaseDC(0, hdc);
			Beep(230, 40);
		}
		for (int i = 600; i < 650; i++) {
			Beep(230, 30);
			desk = GetDC(0);
			StretchBlt(desk, 0, -20, sw, sh + 40, desk, 0, 0, sw, sh, SRCCOPY);
			ReleaseDC(0, desk);
			Beep(730, 50);
		}
		for (int i = 600; i < 650; i++) {
			Beep(120, 30);
			desk = GetDC(0);
			StretchBlt(desk, -20, 0, sw + 40, sh, desk, 0, 0, sw, sh, SRCCOPY);
			ReleaseDC(0, desk);
			Beep(330, 50);
		}
		for (int i = 600; i < 650; i++) {
			Beep(540, 30);
			HDC hdc = GetDC(0);
			int x = SM_CXSCREEN;
			int y = SM_CYSCREEN;
			Beep(620, 30);
			int w = GetSystemMetrics(0);
			int h = GetSystemMetrics(1);
			BitBlt(hdc, rand() % 476, rand() % 476, w, h, hdc, rand() % 346, rand() % 547, NOTSRCERASE);
			ReleaseDC(0, hdc);
			Beep(220, 30);
		}
		LPCSTR text = 0;
		for (int i = 1900; i < 1999; i++) {
			Beep(640, 60);
			HDC hdc = GetDC(0);
			SetBkMode(hdc, 0);
			text = "SandSmile.exe";
			SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
			HFONT font = CreateFontA(43, 32, 0, 0, FW_THIN, 0, 1, 0, ANSI_CHARSET, 0, 0, 0, 0, "Baby Kruffy");
			SelectObject(hdc, font);
			TextOutA(hdc, rand() % x, rand() % y, text, strlen(text));
			DeleteObject(font);
			Beep(430, 60);
			ReleaseDC(0, hdc);
		}
}
