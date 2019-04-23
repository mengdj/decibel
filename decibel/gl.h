#pragma once
#ifndef DEC_INCLUDE_GL_H
#define DEC_INCLUDE_GL_H

#include "stdafx.h"
#include "resource.h"
#include "miniz.h"

typedef struct _OPEN_GL_REN_ENV_ {
	const BOOL *bRunning;						//���У��Ƿ�
	const BOOL *bRecord;						//¼�����Ƿ�
	const BOOL *bMinimize;						//��С�����Ƿ�
	PaUtilRingBuffer* pRingbuff;
	PSRWLOCK pLock;
	PCONDITION_VARIABLE pRVariable;
	PCONDITION_VARIABLE pWVariable;
	BOOL bRestart;								//������ʱ��
	DWORD iTicket;
	DWORD iMinizeTicket[2];						//��С���ͻָ���ʱ��
	POINT point;								//��������
	RECT *pRect;
} OPEN_GL_REN_ENV, *LP_OPEN_GL_REN_ENV;

BOOL			InitGlWindow(HWND, INT, INT, INT, mz_zip_archive*);
BOOL			UnInitGlWindow();
ATOM			RegisterGlCls(WNDPROC, HINSTANCE);
DWORD WINAPI	RenderGl(LPVOID);
VOID			ReSizeGl(INT, INT, INT, INT);
VOID			GlReadPixels(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
VOID			GlTextout(FLOAT, FLOAT, CONST CHAR*);
BOOL			GlUpdateBackgroundFromFile(CONST CHAR*);

extern unsigned char* stbi_load_from_memory(unsigned char const* buffer, int len, int* x, int* y, int* comp, int req_comp);
extern unsigned char* stbi_load(char const* filename, int* x, int* y, int* channels_in_file, int desired_channels);
extern void stbi_image_free(void* retval_from_stbi_load);
extern DWORD LoadResourceFromRes(HINSTANCE hInstace, int resId, LPVOID* outBuff, LPWSTR resType);
extern INT LoadResourceFromZip(mz_zip_archive* pZip, const char* pName, LPVOID* pBuff);
extern BOOL GetPrivateProfileStringLocal(LPCWSTR lpAppName, LPCWSTR lpKeyName, LPCWSTR lpDefault, LPWSTR lpReturnedString, DWORD nSize);
extern BOOL WritePrivateProfileStringLocal(LPCWSTR lpAppName, LPCWSTR lpKeyName, LPCWSTR lpString);
extern INT Char2WChar(const char* cchar, WCHAR* wchar);
extern INT WChar2Char(CONST WCHAR* wchar, CHAR* cchar);
#endif
