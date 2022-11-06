#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<sstream>
#include"mylib.h"
#define MAX_LISTDS 100
#include<fstream>
#define NUMBER_LINES 20
#define MAX_ISBN 6
#define MAX_TENSACH 35
#define MAX_TENTG 35
#define MAX_THELOAI 11
#define MAX_HO 20
#define MAX_TEN 7
#define MAX_VITRI 20
#define UP  72
#define DOWN  80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define BACKSPACE 8


using namespace std;
//==========================Struct Danh Muc Sach==================
struct danhmucsach
{
	string maSach;
	int trangThaiSach; // 0 : Co the cho muon , 1 : da co doc gia muon // 2: da thanh ly
	string viTri;
};
typedef struct danhmucsach DMS;
struct nodeDanhMucSach
{
	DMS data;
	nodeDanhMucSach *pNext;
};
typedef struct nodeDanhMucSach node_DMS;
struct listDanhMucSach
{
	int n=0;
	node_DMS * pHead=NULL, *pTail=NULL;
};
typedef struct listDanhMucSach list_DMS;
//==========================Struct DauSach========================
struct dausach
{
	string ISBN;
	string tenSach;
	int soTrang;
	string tacGia;
	int namXuatBan;
	string theLoai;
	int soLuongMuon=0;// Them Vao De Dem SL muon
	
};
typedef struct dausach dauSach;
struct DauSach
{
	dauSach data;
	list_DMS dms;
};
typedef struct DauSach DAU_SACH;
typedef struct DauSach* pDAU_SACH;
struct listDauSach
{
	int n=0; // SL DauSach
	pDAU_SACH ListDS[MAX_LISTDS];
};
typedef struct listDauSach LIST_DAUSACH;
//==========================struct Ngay Thang=================
struct ngayThang
{
	int ngay;
	int thang;
	int nam;
};
typedef struct ngayThang Ngay_Thang;
//==========================struct Muon Tra==================
struct muonTra
{
	string maSach;
	Ngay_Thang ngayMuon;
	Ngay_Thang ngayTra;
	int trangThai; // 0: dang duoc muon , 1 da tra , 2 lam mat sach
	string tenSach;
};
typedef struct muonTra MT;
struct node_MuonTra
{
	MT data;
	node_MuonTra *pNext;
	//node_MuonTra *pPrev;	
};
typedef struct node_MuonTra node_MT;
struct list_MuonTra
{
	int n=0;
	node_MT *pHead= NULL,*pTail=NULL;
};
typedef struct list_MuonTra list_MT;
//==========================struct DOCGIA ===================
struct docGia
{
	int maThe;
	string ho;
	string ten;
	int phai; // 0 la nam , 1 la nu
	int trangThaiThe; // 0 la bi khoa , 1 la dang hoat dong
};
typedef struct docGia DG;	
struct node_DocGia
{
	DG data;
	node_DocGia *pLeft;
	node_DocGia	*pRight;
	list_MT mt;
};
typedef struct node_DocGia NODE_DG;
typedef NODE_DG* TREE_DG;
void Normal() ;
void HighLight() ;
struct QUAHAN
{
	int maDG;
	string maSach;
	int soNgayQH;
	string tenSach;
};



