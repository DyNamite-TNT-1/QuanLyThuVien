#include "VeKhung.h"
int isFull_DS(LIST_DAUSACH lDS);
int isEmpty_DS(LIST_DAUSACH &lDS);
int Insert_DS(LIST_DAUSACH &lDS, pDAU_SACH &pDS);
void Them_DS(LIST_DAUSACH &lDS);
void XuatDS(pDAU_SACH pDS);
void XuatDanhSach_DS(LIST_DAUSACH lDS);
void Swap_DS(pDAU_SACH &dausach1,pDAU_SACH &dausach2);
void Sort_DS(LIST_DAUSACH &lDS);
pDAU_SACH SearchTen_DS(LIST_DAUSACH lDS, string tensach);
int SearchDS_TheoMa(LIST_DAUSACH lDS, string maDS);
node_DMS* GetNode_DMS(DMS sach);
void AddTailList_DMS(list_DMS &lDMS, DMS sach);
void LoadFileDS(LIST_DAUSACH& lDS);
void initList_DMS(list_DMS& lDMS);
void GhiFileDS(LIST_DAUSACH lDS);
void XuatDauSachTheoPage(LIST_DAUSACH lDS ,int index,int tungdo);
bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN);
string lowerString(string str);
void TimKiemSach(LIST_DAUSACH &lDS);
//===================DMS===============
void initList_DMS(list_DMS& lDMS);
node_DMS* GetNode_DMS(DMS sach);
void AddTailList_DMS(list_DMS &lDMS, DMS sach);
void Nhap_DMS(pDAU_SACH &pDS,bool &);
void Them_Sach(LIST_DAUSACH &lDS);
void XuatDMS(DMS sach , int tungdo);
void XuatListDMS(pDAU_SACH pDS,int &);
node_DMS* Search_DMS(pDAU_SACH pDS, string masach);
void NhapThongTinSach(pDAU_SACH &pDS,bool&);
int position(node_DMS *First, string keySearch);
node_DMS * nodepointer(node_DMS *First, int i);
void Delete_first(node_DMS *&First);
void Delete_after(node_DMS *p);
int Delete_batky(pDAU_SACH &pDS, string keySearch);
void XuLy_XoaSach(LIST_DAUSACH &lDS);
//====================DG=================
void initTREE_DG(TREE_DG &t);
bool IsEmpty(TREE_DG t);
NODE_DG* GetNode_DG(DG dg);
void InsertDGtoTree(TREE_DG &t, DG dg);
int countDG(TREE_DG t);
bool kiem_Tra_Trung(TREE_DG t, int maDG);
int tao_MaDG(TREE_DG t);
void nhap_DG(TREE_DG &t);
NODE_DG* FindMin(TREE_DG t);
NODE_DG* Find_DG(TREE_DG t, int MADG);
bool Edit_DG(TREE_DG &t, DG dg);
int nDG=0;
void Tree_To_Arr(TREE_DG t, DG *arr,int &i);
void Lay_Sach_Do_Vao_Mang(LIST_DAUSACH pDS);
void Arr_To_Tree_MaDG(TREE_DG t, int *arr, int &i);
void Sort_DG_TheoHOTEN(DG* arr, int n);
void XuatDSDG_MADG(TREE_DG t);
void XuatDG1Page_TenHo(TREE_DG t,DG *arr,int index,int tungdo );
void XuatDSDG_HOTEN(TREE_DG t);
void XoaDG(TREE_DG &t);
void ChinhSuaDG(TREE_DG &t);
void Save_1_DG(TREE_DG t,fstream &f);
bool IsDeleted_DG(TREE_DG &t, DG dg);
//===============MT=====================
void initList_MT(list_MT &lMT);
node_MT * GetNodeMT(MT mt);
void ADD_tail_MT(list_MT &lMT , MT mt);
void ADD_head_MT(list_MT &lMT , MT mt);
void Muon_Sach(TREE_DG &t , LIST_DAUSACH &lDS);
void NhapTenSachCanTimKiem(string &kq,LIST_DAUSACH lDS);
void ChonDauSach_MT(LIST_DAUSACH lDS,int &index);
void ChonSach_MT(pDAU_SACH pDS,int &thoat,int &index); 
int SoSachDangMuon(list_MT lMT);
string LayISBN_Tu_Masach(string masach);

node_DMS* SearchDMS_TheoMa(LIST_DAUSACH lDS, string maSach);
bool KiemTra_Muon_Trung_DS(TREE_DG p, string ma_sach);
void Muon_Sach(TREE_DG &t , LIST_DAUSACH &lDS);
void TraSach(TREE_DG &t, LIST_DAUSACH &lDS);
void XuatDS_MT(MT mt, int tungdo);
void MatSach(TREE_DG &t, LIST_DAUSACH &lDS);
void DS_QUAHAN(TREE_DG t);
void DanhSachCacSachDangMuon(TREE_DG t, LIST_DAUSACH lDS);
void top10sach(LIST_DAUSACH lDS);
//===================================================================
int isFull_DS(LIST_DAUSACH lDS)
{
	return lDS.n==MAX_LISTDS;
}
int isEmpty_DS(LIST_DAUSACH &lDS)
{
	return lDS.n==0;
}
int Insert_DS(LIST_DAUSACH &lDS, pDAU_SACH &pDS)
{
	if(isFull_DS(lDS))
	{
		return 0;
	}
	lDS.ListDS[lDS.n]=pDS;
	lDS.n++;
	return 1;
}
void GhiFileDS(LIST_DAUSACH lDS)
{
		ofstream outFile;
		outFile.open("DauSach.txt",ios::out);
		outFile << lDS.n << endl;
		for (int i = 0; i < lDS.n; i++)
		{
			outFile << lDS.ListDS[i]->data.tenSach << endl;
			outFile << lDS.ListDS[i]->data.ISBN << endl;
			outFile << lDS.ListDS[i]->data.tacGia << endl;
			outFile << lDS.ListDS[i]->data.theLoai << endl;
			outFile << lDS.ListDS[i]->data.soTrang << endl;
			outFile << lDS.ListDS[i]->data.namXuatBan << endl;
			outFile << lDS.ListDS[i]->data.soLuongMuon << endl;
			
			outFile << lDS.ListDS[i]->dms.n << endl;
			for (node_DMS* p  = lDS.ListDS[i]->dms.pHead ; p != NULL ;  p = p->pNext )
			{
				outFile << p->data.maSach << endl;
				outFile << p->data.trangThaiSach << endl;
				outFile << p->data.viTri << endl;
			}
		}
	outFile.close();
}
void LoadFileDS(LIST_DAUSACH& lDS)
{
	fstream inFile;
	dauSach info;
	inFile.open("DauSach.txt", ios::in);
	pDAU_SACH pDS;
	DMS dms;
	int sodausach, sosach;
	if (inFile.is_open())
	{
		string temp;
		inFile >> sodausach;
		getline(inFile, temp);

		for (int i = 0; i < sodausach; i++)
		{
			pDS = new DAU_SACH;
			if (pDS == NULL) continue;

			// load thong tin vao bien tam.

			getline(inFile, info.tenSach);
			getline(inFile, info.ISBN);
			getline(inFile, info.tacGia);
			getline(inFile, info.theLoai);
			inFile >> info.soTrang;
			inFile >> info.namXuatBan;
			inFile >> info.soLuongMuon;
			// load thong tin vao dau sach
			pDS->data = info;

			inFile >> sosach;
			getline(inFile, temp);
			initList_DMS(pDS->dms);
			for (int j = 0; j < sosach; j++)
			{
				getline(inFile, dms.maSach);
				inFile >> dms.trangThaiSach;
				getline(inFile, temp);
				getline(inFile, dms.viTri);
				AddTailList_DMS(pDS->dms, dms);
			}

			Insert_DS(lDS, pDS);
		}
	}
	else 
	{
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}

inFile.close();
}
bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN)
{
	for (int i = 0; i < lDS.n; i++)
	{
		if (lDS.ListDS[i]->data.ISBN == ISBN)
			return true;
	}
	return false;
}
void Them_DS(LIST_DAUSACH &lDS)
{
	int x=90;
	int y=20;
	int vitri=0;
	Normal();
	VeBoxNhapDS();
	pDAU_SACH pDS = new DAU_SACH;
	string ISBN="";
	string tenSach="";
	string theLoai="";
	string tacGia="";
	int namXuatBan=0;
	int soTrang=0;
	bool ESC=false;
	while(true)
	{
		switch(vitri)
		{
			case 0: gotoxy(x+13,y+1);
					NhapISBN(ISBN,vitri,ESC);
					break;
			case 1: gotoxy(x+13,y+3);
					NhapTenSach(tenSach,vitri,ESC);
					break;
			case 2: gotoxy(x+13,y+5);
					NhapSoTrang(soTrang,vitri,ESC);
					break;
			case 3: gotoxy(x+13,y+7);
					NhapTacGia(tacGia,vitri,ESC);
					break;
			case 4: gotoxy(x+13,y+9);
					NhapNamXB(namXuatBan,vitri,ESC);
					if (2020 < namXuatBan )
					{
						vitri=4;
					}
					break;
			case 5: gotoxy(x+13,y+11);
					NhapTheLoai(theLoai,vitri,ESC);
					break;
			case 6: if(ISBN==""|| tenSach==""||theLoai==""||namXuatBan==0||soTrang==0)
					{
						gotoxy(105,40);
						cout<<"CAC TRUONG DU LIEU KHONG DUOC DE TRONG!";
						Sleep(3000);
						gotoxy(105,40);
						cout<<"                                       ";					
						vitri=0;
					}
					else if(SearchISBN_DS(lDS,ISBN)==true)
					{
						gotoxy(105,40);
						cout<<"MA SACH DA TON TAI VUI LONG NHAP LAI";
						Sleep(3000);
						gotoxy(105,40);
						cout<<"                                    ";											
						vitri=0;		
					}
					else if(ISBN.length()<6)
					{
						gotoxy(105,40);
						cout<<"ISBN PHAI CO DUNG 6 KY TU";
						Sleep(3000);
						gotoxy(105,40);
						cout<<"                         ";					
						vitri=0;
					}
					else
					{
						
						ShowCur(false);
						gotoxy(105,40);
						cout<<"BAN CO MUON LUU DAU SACH HAY KHONG";
						gotoxy(105,42);
						cout<<"ENTER: LUU";
						gotoxy(130,42);
						cout<<"ESC: THOAT";	
						while(_kbhit())
						{
						
							int c=_getch();
							if(c==27)
							{
								ESC=true;
								return;
							}
							else if(c==13)
							{
								gotoxy(105,40);
								cout<<"                                       ";
								gotoxy(105,40);
								cout<<"LUU THANH CONG";
								Sleep(2000);
								pDS->data.ISBN=In_Hoa_String(ISBN);
								pDS->data.namXuatBan=namXuatBan;
								pDS->data.soTrang=soTrang;
								pDS->data.tacGia=Chuan_Hoa_String(tacGia);
								pDS->data.tenSach=Chuan_Hoa_String(tenSach);
								pDS->data.theLoai=Chuan_Hoa_String(theLoai);
								Insert_DS(lDS,pDS);
								return;
							}
						}
					}
					break;		
		}
		
		if(ESC==true)
		{
			break;
		}
	}
	
}
char td[][50] ={" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
int MenuDongDS(char td [][50],int so_item){
	int cot = 38;
	int dong = 4;
  int chon =0;
  int i; 
  HighLight();
  gotoxy(cot,dong+chon);
  cout << char(179);
  char kytu;
do {
  kytu = getch();
  if (kytu==-32) kytu = getch();
  switch (kytu) {
    case UP :if (chon >0)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon*2);cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon*2); 	cout << char(179);  				
  			  }
  			  break;
  	case DOWN :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon*2);	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon*2); 	cout <<char(179);
  				
  			  }
  			  break;
  	case 13 : Normal();
	  return chon+1;
  	case 27 : Normal();
	  return -1 ;
  }  // end switch
  } while (1);
}
void XuatDS(pDAU_SACH pDS, int tungdo)
{
	Normal();
	ShowCur(false);
	gotoxy(40, tungdo);
	cout << pDS->data.ISBN;
	gotoxy(47, tungdo);
	cout << pDS->data.tenSach;
	gotoxy(87, tungdo);
	cout << pDS->data.soTrang;
	gotoxy(97, tungdo);
	cout << pDS->data.tacGia;
	gotoxy(137, tungdo);
	cout << pDS->data.namXuatBan;
	gotoxy(145, tungdo);
	cout << pDS->data.theLoai;
	Normal();
} 
void XuatDauSachTheoPage(LIST_DAUSACH lDS ,int index,int tungdo)
{
	
	int SoSach1Trang=20;
	tungdo = 4;
	index--;
	if(lDS.n==0)
	{
		return;
	}
	for (int i =  SoSach1Trang * index;  i < SoSach1Trang*( 1 + index)  && i <  lDS.n ; i++)
	{
		
		XuatDS(lDS.ListDS[i],tungdo);
		tungdo+=2;
	}
}
void XuatDanhSach_DS(LIST_DAUSACH lDS)
{
	Normal();
	int tongtrang = (lDS.n/20)+1;
	int tttrang = 1;
	int tungdo;
	Sort_DS(lDS);
	int thoat;
MENUDS:
	Normal();
	Box_Xuat_DS();
	XuatDauSachTheoPage(lDS,tttrang,tungdo);
	int c;
	do
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 224 || c == 0)
				c = _getch();
			switch (c)
			{
			case ENTER:
				int vitri;
				if(tttrang==tongtrang)
				{
					int TrangCuoi = lDS.n-(20*(tongtrang-1));
					vitri = MenuDongDS(td,TrangCuoi);
					if(vitri==-1)
					{
						Xoa1Khoang();
						goto MENUDS;
					}
					ShowCur(true);
					Xoa1Khoang();
					XuatListDMS(lDS.ListDS[vitri-1+20*(tttrang-1)],thoat);
					if(thoat==1)
					{
						Xoa1Khoang();
						goto MENUDS;
					}		
				}
				else
				{
				vitri =MenuDongDS(td,20);
				if(vitri==-1)
				{
						Xoa1Khoang();
						goto MENUDS;
				}
				ShowCur(true);
				Xoa1Khoang();
				XuatListDMS(lDS.ListDS[vitri-1+20*(tttrang-1)],thoat);	
				if(thoat==1)
					{
						Xoa1Khoang();
						goto MENUDS;
					}		
				}
				break;	
			case LEFT:
				Xoa_Man_Hinh_DS();
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				XuatDauSachTheoPage(lDS, tttrang,tungdo);
				break;

			case RIGHT:
				Xoa_Man_Hinh_DS();
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				XuatDauSachTheoPage(lDS, tttrang,tungdo);
				break;
			case  27:
				return;
			}
		}
		ShowCur(false);
		gotoxy(80, 46);
		SetColor(4);
		cout << "HotKey: KEY LEFT, KEY RIGHT, ESC:THOAT";
		gotoxy(88, 45);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}while(true);
}
void Swap_DS(pDAU_SACH &dausach1,pDAU_SACH &dausach2)
{
	DAU_SACH * temp = dausach1;
	dausach1= dausach2;
	dausach2=temp;
} 
void Sort_DS(LIST_DAUSACH &lDS)
{
	pDAU_SACH temp = NULL;
	//sap xep theo the loai
	for (int i = 0; i < lDS.n - 1; i++)
	{
		for (int j = i + 1; j < lDS.n; j++)
		{
			if (lDS.ListDS[i]->data.theLoai > lDS.ListDS[j]->data.theLoai)
			{
				temp = lDS.ListDS[i];
				lDS.ListDS[i] = lDS.ListDS[j];
				lDS.ListDS[j] = temp;
			}
			else if (lDS.ListDS[i]->data.theLoai == lDS.ListDS[j]->data.theLoai)
			{
				if (lDS.ListDS[i]->data.tenSach > lDS.ListDS[j]->data.tenSach)
				{
					temp = lDS.ListDS[i];
					lDS.ListDS[i] = lDS.ListDS[j];
					lDS.ListDS[j] = temp;
				}
			}
		}
	}
}
pDAU_SACH SearchTen_DS(LIST_DAUSACH lDS, string tensach)
{
	pDAU_SACH temp ;
	for (int i = 0; i < lDS.n; i++)
	{
		temp = lDS.ListDS[i];
		if (temp->data.tenSach == tensach)
		{		
			return temp;
		}
	}
	temp = NULL;
	return temp;
}
int Dem_Sach_CON_MUON_DUOC(pDAU_SACH pDS)
{
	int n=0;
	for (node_DMS* p = pDS->dms.pHead; p != NULL; p = p->pNext)
		if (p->data.trangThaiSach == 0)
		n++;
	return n;
}
int tong_so_sach(pDAU_SACH x)
{
	int n = 0;
	for (node_DMS* p = x->dms.pHead; p != NULL; p = p->pNext)
		n++;
	return n;
}
string lowerString(string str) {
	string st = str;
	for (int i = 0 ; i<st.length(); i++) {
		st[i] = tolower(st[i]);
	}
	return st;
}
void TimKiemSach(LIST_DAUSACH &lDS)
{
	bool thoat=false;
	string tenSach="";
	Box_Xuat_DS();
	Box_NhapSachTimKiem();
	gotoxy(175,3);
	Normal();
	ShowCur(true);
	int index=1;
	int tungdo=4;
	cout << tenSach;
	int demKitu= (int)tenSach.length();
	int x,y;
	int demSpace=0;
	while(true)
	{
		
		while (_kbhit())
		{
			LIST_DAUSACH lDS3;
			int c = _getch();
			// Ten sach  Chi Nhan Chu Thuong hoac Chu Hoa ,so, va Toi Da 35 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
			|| (c >=  48 && c <= 57) || c == 32) && demKitu < MAX_TENSACH)
			{
				gotoxy(175+tenSach.length(),3);
				ShowCur(true);
				if(demSpace==1 && c==32)
				{
					demKitu++;
					cout << (char)c;
					tenSach += (char)c;
					demSpace = 0;
				}
				else if (c != 32)
				{
					demKitu++;
					cout << (char)c;
					tenSach += (char)c;
					demSpace = 1;
				}
				Xoa_Man_Hinh_DS();
				LIST_DAUSACH lDS2;
				int j=0;
				for(int i=0;i<lDS.n;i++)
				{
					string st1 = lowerString(lDS.ListDS[i]->data.tenSach);
					string st2 = lowerString(tenSach);
//					x=st1.find(st2);
//					x=lDS.ListDS[i]->data.tenSach.find(tenSach);
					if (strstr(st1.c_str(), st2.c_str())!=NULL)
					{
						lDS2.ListDS[j]=lDS.ListDS[i];								
						j++;
						lDS2.n++;
					}
//					if(x!= string::npos)
//					{
//						lDS2.ListDS[j]=lDS.ListDS[i];								
//						j++;
//						lDS2.n++;
//					}
					XuatDauSachTheoPage(lDS2,index,tungdo);
				}	
			}
			else if (c==13)// neu la phim enter
			{	
				Xoa_Man_Hinh_DS();
				LIST_DAUSACH lDS2;
				int j=0;
				for(int i=0;i<lDS.n;i++)
				{
						
//					x=lDS.ListDS[i]->data.tenSach.find(tenSach);
					string st1 = lowerString(lDS.ListDS[i]->data.tenSach);
					string st2 = lowerString(tenSach);
					if (strstr(st1.c_str(), st2.c_str())!=NULL)
					{
						lDS2.ListDS[j]=lDS.ListDS[i];								
						j++;
						lDS2.n++;
					}
//					x=st1.find(st2);		
//					if(x!= string::npos)
//					{
//						lDS2.ListDS[j]=lDS.ListDS[i];								
//						j++;
//						lDS2.n++;
//					}
				}	
				XuatDanhSach_DS(lDS2);
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				
				gotoxy(175+tenSach.length()-1,3);cout<<" ";
				gotoxy(175+tenSach.length()-1,3);
				demKitu--;
				tenSach.erase(tenSach.length() - 1, 1);
				Xoa_Man_Hinh_DS();
				LIST_DAUSACH lDS2;
				int k=0;
				for(int i=0;i<lDS.n;i++)
				{
//					x=lDS.ListDS[i]->data.tenSach.find(tenSach);
					string st1 = lowerString(lDS.ListDS[i]->data.tenSach);
					string st2 = lowerString(tenSach);
					if (strstr(st1.c_str(), st2.c_str())!=NULL)
					{
						lDS2.ListDS[k]=lDS.ListDS[i];								
						k++;
						lDS2.n++;
					}
//					x=st1.find(st2);
//					if(x!= string::npos)
//					{
//						lDS2.ListDS[k]=lDS.ListDS[i];
//						k++;
//						lDS2.n++;
//					}
				}	
				XuatDauSachTheoPage(lDS2,index,tungdo);
				gotoxy(175+tenSach.length(),3);	
				ShowCur(true);		
			}
			else if (c == 224)
			{
			
			}
			else if(c==27)
			{
				return;
			}
			
		}
	}
	getch();
	
}
//=====================DMS==========================
void initList_DMS(list_DMS& lDMS)
{
	lDMS.n = 0;
	lDMS.pHead = lDMS.pTail = NULL;
}
node_DMS* GetNode_DMS(DMS sach)
{
	node_DMS *p = new node_DMS;
	if (p == NULL) 
	{
		return NULL; // Khong Du Bo Nho De Cap Phat
	}
	p->data = sach;
	p->pNext = NULL;
	return p;	
}	
void AddTailList_DMS(list_DMS &lDMS, DMS sach)
{
	node_DMS *p = GetNode_DMS(sach);
	if (lDMS.pHead == NULL) 
	{
		lDMS.pHead = lDMS.pTail = p; // neu danh sach rong node p moi them la ptail
	}
	else
	{
		lDMS.pTail->pNext = p;//p ->next cua tail la p 
		lDMS.pTail = p;// cap nhat lai ptail 
	}
	lDMS.n++;
		
}
void XuatDMS(DMS sach , int tungdo)
{
	gotoxy(40, tungdo);
	cout<<sach.maSach;
	gotoxy(60,tungdo);
	if(sach.trangThaiSach==0)
	{
		cout<<"CHO MUON DUOC";
	}
	else if(sach.trangThaiSach==1)
	{
		cout<<"DA DUOC MUON";
	}
	else if(sach.trangThaiSach==2)
	{
		cout<<"DA THANH LY";
	}
	gotoxy(90,tungdo);
	cout<<sach.viTri;
	Normal();
}
void XuatDMSTheoPage(pDAU_SACH pDS,int tungdo,int index)
{	
	Normal();
	int soDMS1Trang=20;
	tungdo = 4;
	if (pDS->dms.pHead == NULL && pDS->dms.pTail == NULL)// danh sach rong
		return;
	index--;
	index *= soDMS1Trang;
	int count = 0;
	node_DMS * temp = NULL;
	for ( temp = pDS->dms.pHead ; temp != NULL  && count < index ; temp = temp->pNext)
	{
		count++;
	}
	for (int i = 0; i < soDMS1Trang && temp != NULL; i++)
	{
		XuatDMS(temp->data,tungdo);
		tungdo+=2;
		temp = temp->pNext;
	}
	return;
}	
void XuatListDMS(pDAU_SACH pDS,int &thoat)
{
	Normal();
	int tongtrang = (pDS->dms.n/20)+1;
	int tttrang = 1;
	int tungdo;
	int n=0;
	thoat=0;// 
	VeKhungDMS();
	XuatDMSTheoPage(pDS,tttrang,tungdo);
	SetColor(4);
	gotoxy(150,2);cout<<"TEN SACH: "<<pDS->data.tenSach;
	for (node_DMS* p = pDS->dms.pHead; p != NULL; p = p->pNext)
    {
		if (p->data.trangThaiSach == 0)
		n++;
	}
	gotoxy(150,3);cout<<"SL CON: "<<n;
	Normal();
	int c;
	do
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 224 || c == 0)
				c = _getch();
			switch (c)
			{
			case LEFT:	
			
				XoaKhungDMS();
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				XuatDMSTheoPage(pDS, tungdo,tttrang);
				break;
			case RIGHT:
				XoaKhungDMS();
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				XuatDMSTheoPage(pDS, tungdo,tttrang);
				break;
			case  27:
				thoat = 1;
				return;
			}
		}
		ShowCur(false);
		gotoxy(80, 46);
		SetColor(4);
		cout << "HotKey: KEY LEFT, KEY RIGHT, ESC:THOAT";
		gotoxy(88, 45);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}while(true);
}
void Them_Sach(LIST_DAUSACH &lDS)
{
	Normal();
	int tongtrang = (lDS.n/20)+1;
	int tttrang = 1;
	int tungdo;
	bool thoat=false;
ThemSach:
	Sort_DS(lDS);
	Box_Xuat_DS();
	XuatDauSachTheoPage(lDS,tttrang,tungdo);
	int c;
	do
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 224 || c == 0)
				c = _getch();
			switch (c)
			{
			case ENTER:
				int vitri;
				if(tttrang==tongtrang)
				{
					int TrangCuoi = lDS.n-(20*(tongtrang-1));
					vitri = MenuDongDS(td,TrangCuoi);
					if(vitri==-1)
					{
						Xoa1Khoang();
						goto ThemSach;
					}
					ShowCur(true);
					Xoa1Khoang();
					Nhap_DMS(lDS.ListDS[vitri-1+20*(tttrang-1)],thoat);
					if(thoat==true)
					{
						Xoa1Khoang();
						goto ThemSach;
					}		
				}
				else
				{
				vitri =MenuDongDS(td,20);
				if(vitri==-1)
				{
						Xoa1Khoang();
						goto ThemSach;
				}
				ShowCur(true);
				Xoa1Khoang();
				Nhap_DMS(lDS.ListDS[vitri-1+20*(tttrang-1)],thoat);	
				if(thoat==true)
					{
						Xoa1Khoang();
						goto ThemSach;
					}		
				}
				goto ThemSach;
				break;	
			case LEFT:
				Xoa_Man_Hinh_DS();
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				XuatDauSachTheoPage(lDS, tttrang,tungdo);
				break;

			case RIGHT:
				Xoa_Man_Hinh_DS();
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				XuatDauSachTheoPage(lDS, tttrang,tungdo);
				break;
			case  27:
				return;
			
			}
		}
		ShowCur(false);
		gotoxy(80, 46);
		SetColor(4);
		cout << "HotKey: KEY LEFT, KEY RIGHT, ESC:THOAT";
		gotoxy(88, 45);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}while(true);
}
node_DMS* Search_DMS(pDAU_SACH pDS, string masach)
{
	node_DMS* p;
	p = pDS->dms.pHead;
	while (p != NULL && p->data.maSach != masach)
		p = p->pNext;
	return (p);
}
bool check_Trung_Ms(pDAU_SACH pDS, string masach)
{
	node_DMS* p;
	p = pDS->dms.pHead;
	while (p != NULL )
	{
		if(masach==p->data.maSach)return false;
		else
		p=p->pNext;
		
	}
	return true;
}
void NhapThongTinSach(pDAU_SACH &pDS,bool &ESC)
{
	DMS sach;
	Normal();
	ShowCur(true);
	bool kt=false;
	ESC = false;
	int stt = pDS->dms.n+1;
	string maSach=pDS->data.ISBN + to_string(stt);
	kt = check_Trung_Ms(pDS,maSach);
	while(kt ==false)
	{
		stt++;
		maSach=pDS->data.ISBN + to_string(stt);
		kt=check_Trung_Ms(pDS,maSach);
	}	
	gotoxy(95,6);
	cout<<maSach;
	int trangthai=0;
	string vitri="";
	gotoxy(95,10);
	cout<<"CO THE CHO MUON";
	bool luu;
	NhapThongTinSach:
		gotoxy(95,8);
		NhapViTri(vitri,ESC,luu);
		if(ESC==true)
		{
			return;
		}
		if(vitri.length()==0)
		{
			gotoxy(90,14);
			cout<<"CAC TRUONG DU LIEU KHONG DUOC DE TRONG";
			Sleep(1000);
			gotoxy(90,14);
			cout<<"                                      ";
			goto NhapThongTinSach;
		}
		if (luu==true)
		{
			sach.maSach=maSach;
			sach.trangThaiSach=trangthai;
			sach.viTri=vitri;
			AddTailList_DMS(pDS->dms,sach);
			gotoxy(90,15);
			cout<<"LUU THANH CONG";
			Sleep(1000);
			gotoxy(90,15);
			cout<<"              ";
			XoaBoxNhapSach();
		}
}
void Nhap_DMS(pDAU_SACH &pDS,bool &thoat)
{
	thoat = false;
	bool ESC=false;
	int sosach=0;
	Normal();
	gotoxy(90,4);
	cout<<"SO LUONG SACH: ";
	int k=NhapSoSach(sosach);
	if(k==-1)
	{
		thoat=true;
	}
	else if(k==1)
	{
		BoxNhapSach();
		for(int i=0;i<sosach;i++)
		{
			NhapThongTinSach(pDS,ESC);
			if(ESC==true)
			{
				XoaBoxNhapSach2();
				return;
			}
		}
		XoaBoxNhapSach2();
	}
}
int position(node_DMS *First, string keySearch)
{
	int vitri;
	node_DMS * q;
	q = First;
	vitri = 1;
	if (q == NULL)
		return(-1);
	while (q != NULL && q->data.maSach != keySearch)
	{
		
		q = q->pNext;
		vitri++;
	}
	gotoxy(10,40);cout<<vitri;
	return vitri;
}

node_DMS * nodepointer(node_DMS *First, int i)
{
	node_DMS * p;
	int vitri = 1;
	p = First;
	while (p != NULL && vitri < i)
	{
		p = p->pNext;
		vitri++;
	}
	return(p);
}
void Delete_first(node_DMS *&First)
{
	node_DMS *p;
	if (First == NULL)
		return;
	else
	{
		p = First;    // nut can xoa la nut dau
		First = First->pNext;
		delete p;
	}
}

void Delete_after(node_DMS *p)
{
	node_DMS * q;

	q = p-> pNext;  // q chi nut can xoa
	p->pNext = q-> pNext;
	
	delete q;
}

int Delete_batky(pDAU_SACH &pDS, string keySearch)
{
	int pos;
	pos = position(pDS->dms.pHead, keySearch);
	if (pos > pDS->dms.n   || pos == -1)
	{
		return  -1;
	}
	// truong hop xoa dau
	else if (pos == 1)
	{
		Delete_first(pDS->dms.pHead );
		pDS->dms.n--;
		return 1;
	}
	else
	{  //p chi toi nut truoc nut can xoa
		node_DMS  *p = nodepointer(pDS->dms.pHead , pos - 1);
		Delete_after(p);

		// truong hop xoa duoi, thi phai cap nhat lai pTail, rat quan trong cho nay.@@
		if (pos == pDS->dms.n)
		{
			pDS->dms.pTail = p;
		}
		pDS->dms.n--;
		return 1;
	}
}
void XuLy_XoaSach(LIST_DAUSACH &lDS)
{
	Normal();
		while(1)
			{
				ShowCur(true);
				gotoxy(90,2);
				SetColor(4);cout<<"HAY NHAP VAO MA SACH";
				Normal();
				gotoxy(90,3);
				BoxNhapMaSach();
				string masach="";
				string ISBN="";
				bool ESC=false;
				bool luu=false;
				gotoxy(100,4);
				NhapMaSach(masach,ESC,luu);
				masach=In_Hoa_String(masach);
				if(ESC==true)
				{
					Xoa1Khoang();
					return;
				}		
				ISBN=LayISBN_Tu_Masach(masach);
				int index=SearchDS_TheoMa(lDS,ISBN);
				if(index==-1)
				{
					SetColor(4);
					gotoxy(95,6);cout<<"MA SACH KHONG DUNG";
					getch();
					gotoxy(95,4);cout<<"                                 ";
					gotoxy(95,6);cout<<"                                 ";
					Normal();
				}
				else
				{
					string keySach=masach;
					node_DMS *sach=SearchDMS_TheoMa(lDS,masach);
					if(sach==NULL)
					{
						SetColor(4);
						gotoxy(95,6);cout<<"MA SACH KHONG DUNG";
						getch();
						gotoxy(95,4);cout<<"                                 ";
						gotoxy(95,6);cout<<"                                 ";
						Normal();
					}
					else
					{
						SetColor(4);
						gotoxy(95,6);cout<<"THONG TIN SACH";
						Normal();
						gotoxy(90,8);cout<<"MA SACH:"<<sach->data.maSach;
						gotoxy(90,9);cout<<"TEN SACH: " << lDS.ListDS[index]->data.tenSach;
						gotoxy(90,10);cout<<"TRANG THAI SACH:";
						if(sach->data.trangThaiSach==0)
						{
							cout<<"CHO MUON DUOC";
						}
						else if(sach->data.trangThaiSach==1)
						{
							cout<<"DA DUOC MUON";
						}
						else if(sach->data.trangThaiSach==2)
						{
							cout<<"DA THANH LY";
						}
						gotoxy(90,11);cout<<"VI TRI: " <<sach->data.viTri;
						if(sach->data.trangThaiSach==1||sach->data.trangThaiSach==2)
						{
							SetColor(4);
							gotoxy(95,15);cout<<"SACH DA CO NGUOI MUON KHONG THE XOA";
							getch();
							gotoxy(95,4);cout<<"                                   ";
							gotoxy(95,15);cout<<"                                   ";
							Normal();
							return;
						}
						else
						{
							ShowCur(false);
							SetColor(4);
							gotoxy(90,16);
							cout<<"BAN CO MUON XOA SACH HAY KHONG";
							gotoxy(90,18);
							cout<<"ENTER: DONG Y";
							gotoxy(110,18);
							cout<<"ESC: THOAT";
							Normal();								
							while(kbhit)
							{
								int c=_getch();
								if(c==27)
								{
									ESC=true;
									return;
								}	
								else if(c==13)
								{
									Delete_batky(lDS.ListDS[index],keySach);
									SetColor(4);
									gotoxy(90,16);
									cout<<"                               ";
									gotoxy(90,18);
									cout<<"                ";
									gotoxy(110,18);
									cout<<"                ";
									gotoxy(95,15);cout<<"XOA THANH CONG";
									getch();
									Xoa1Khoang();
									return;
								}
							}
						}					
					}
				}		
			}
}

//====================DOCGIA============
void initTREE_DG(TREE_DG &t)
{
	nDG = 0;
	t = NULL;
}

bool IsEmpty(TREE_DG t)
{
	return t == NULL;
}

NODE_DG* GetNode_DG(DG dg)
{
	NODE_DG *p = new NODE_DG;
	if (p == NULL) 
	{
		return NULL;
	}
	initList_MT(p->mt);
	p->data = dg;
	p->pLeft =NULL;
	p->pRight = NULL;
	return p;
}

void InsertDGtoTree(TREE_DG &t, DG dg)
{
	if (t == NULL) 
	{
		t = GetNode_DG(dg);
		nDG++;
	}
	else 
	{
		if (t->data.maThe > dg.maThe)
		{
			InsertDGtoTree(t->pLeft, dg);
		}
		else if (t->data.maThe < dg.maThe)
		{
			InsertDGtoTree(t->pRight, dg);
		}		
	}
}
int countDG(TREE_DG t)
{
	int c = 1;             // ban than node duoc dem la 1;
	if (t == NULL)
		return 0;
	else
	{
		c += countDG(t->pLeft);
		c += countDG(t->pRight);
		return c;
	}
}
bool kiem_Tra_Trung(TREE_DG t, int maDG)
{
	if (t==NULL)
	{
		return false;
	}
	else
	{
		if(t->data.maThe==maDG)
		{
			return true;
		}
		else if (t->data.maThe > maDG)
		{
			 kiem_Tra_Trung(t->pRight,maDG);
		}
		else 
		{
			 kiem_Tra_Trung(t->pLeft,maDG);
		}
	}
}
int tao_MaDG(TREE_DG t)
{
	int maDG;
	//random Tu 1 Den 999
	do
	{
		maDG = rand() % (999 - 1 + 1) + 1;
	} while (kiem_Tra_Trung(t,maDG)==true);
	return maDG;
}
void Swap_DG(DG &dg1 , DG &dg2)
{
	DG temp ;
	temp = dg1;
	dg1=dg2;
	dg2=temp;
}
void nhap_DG(TREE_DG &t)
{
	DG dg;
	Normal();
	int x=90;
	int y=20;
	int vitri=0;
	string ho="";
	string ten="";
	int phai;
	int tinhtrang;
	bool ESC=false;
	Box_Nhap_DG();
	gotoxy(x+13,y+1);
	dg.maThe=tao_MaDG(t);
	cout<<dg.maThe;
	while (true)
	{
		switch(vitri)
		{
			case 0: gotoxy(x+13,y+3);
					NhapHo(ho,vitri,ESC);
					break;
			case 1: gotoxy(x+13,y+5);
					NhapTen(ten,vitri,ESC);
					break;
			case 2: gotoxy(x+13,y+7);
					NhapPhai(phai,vitri,ESC);
					break;
			case 3: gotoxy(x+13,y+9);
					NhapTrangThai(tinhtrang,vitri,ESC);
					break;
			case 4: if(ho==""|| ten=="")
					{
						gotoxy(95,32);
						cout<<"CAC TRUONG DU LIEU KHONG DUOC DE TRONG!";
						vitri=0;
					}
					else 
					{
						Normal();
						gotoxy(95,32);
						cout<<"                                       ";
						ShowCur(false);
						gotoxy(95,32);
						cout<<"BAN CO MUON LUU DG HAY KHONG";
						gotoxy(95,33);
						cout<<"ENTER: LUU";
						gotoxy(120,33);
						cout<<"ESC: THOAT";	
						while(1)
						{
						
							int c=_getch();
							if(c==27)
							{
								ESC=true;
								return;
							}
							else if(c==13)
							{
								gotoxy(95,32);
								cout<<"                                       ";
								gotoxy(95,32);
								cout<<"LUU THANH CONG";
								Sleep(2000);
								dg.ho=Chuan_Hoa_String(ho);
								dg.ten=Chuan_Hoa_String(ten);
								dg.phai=phai;
								dg.trangThaiThe=tinhtrang;
								InsertDGtoTree(t,dg);
								return;
							}
						}
					}
		}
		if(ESC==true)
		{
			break;
		}
	}
}
NODE_DG* FindMin(TREE_DG t)
{
	while (t->pLeft != NULL)
	{ 
		t = t->pLeft;
	}
	return t;
}

NODE_DG* Find_DG(TREE_DG t, int MADG)
{
	if (t)
	{
		if (t->data.maThe == MADG)
			return t;
		else if (t->data.maThe < MADG)
			return Find_DG(t->pRight, MADG);
		else
			return Find_DG(t->pLeft, MADG);
	}
	else
		return NULL;
}
bool IsDeleted_DG(TREE_DG &t, DG dg)
{
	if (t == NULL)
		return false;
	else
	{
		// Tim Ma Doc Gia Can Xoa
		if (dg.maThe > t->data.maThe)
		{
			return IsDeleted_DG(t->pRight, dg);
		}
		else if (dg.maThe < t->data.maThe)
		{
			return IsDeleted_DG(t->pLeft, dg);
		}
		// Tien hanh Xoa Sau Khi Tim Duoc Ma DG Can Xoa	 
		else 
		{
			//case 1:Not La
			if (t->pLeft == NULL && t->pRight == NULL)
			{
				delete t; 
				t = NULL;
				nDG--;
			}
			else if (t->pLeft == NULL)// case 2: co 1 Con
			{
				NODE_DG* temp = t;
				t = t->pRight;
				delete temp;
				nDG--;
			}
			else if (t->pRight == NULL)
			{
				NODE_DG* temp = t;
				t = t->pLeft;
				delete temp;
				nDG--;
			}
			// Case 3: Not 2 Con
			else {
				NODE_DG* temp = FindMin(t->pRight);// Tim node Trai Cung Cua Cay con Phai

				// copy du lieu vao .
				t->data = temp->data;
				t->mt = temp->mt;
				return IsDeleted_DG(t->pRight, temp->data);
			}
			return true;
		}
	}
}
void Tree_To_Arr(TREE_DG t, DG *arr,int &i)// DUyet LNR de MANG co thu tu tang dan
{
	if (t == NULL)
	{
		return;	
	}	
	Tree_To_Arr(t->pLeft, arr,i); 
	arr[i++] = t->data;
	Tree_To_Arr(t->pRight, arr,i);
}
void Arr_To_Tree_MaDG(TREE_DG t, int *arr, int &i)// DUyet LNR de MANG co thu tu tang dan
{
	if (t == NULL)
	{
		return;	
	}	
	Arr_To_Tree_MaDG(t->pLeft, arr,i); 
	arr[i++] = t->data.maThe;
	Arr_To_Tree_MaDG(t->pRight, arr,i);
}
void Sort_DG_TheoHOTEN(DG* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{  
			if (arr[i].ten.compare(arr[j].ten) >0 )
			{
				
				Swap_DG(arr[i], arr[j]);
			} 
			else if (arr[i].ten.compare(arr[j].ten) == 0 )
			{ 
				if (arr[i].ho.compare(arr[j].ho) > 0)
				{ 
					Swap_DG(arr[i], arr[j]);
				}
			}
		}
	}
}
void Xuat1DG(DG dg , int td)
{
	int x=wherex();
	int y=wherey();
	Normal();
	gotoxy(76,td);
	cout<<dg.maThe;
	gotoxy(76+12,td);
	cout<<dg.ho;
	gotoxy(76+12+30,td);
	cout<<dg.ten;
	gotoxy(76+12+30+15,td);
	if(dg.phai==0) cout<<"NAM";
	else cout<<"NU";
	gotoxy(76+12+30+15+7,td);
	if(dg.trangThaiThe==0) cout<<"BI KHOA";
	else cout<<"HOAT DONG";
	gotoxy(x,y);
}
void XuatDG1Page(TREE_DG t,int *arr,int index,int tungdo )
{
	int soDG1Page=20;
	int soDG=countDG(t);
	tungdo=2;
	NODE_DG*temp=NULL;	
	index--;
	for(int i=0+soDG1Page*index;i<(soDG1Page+soDG1Page*index)&&i<soDG;i++)
	{
		temp=Find_DG(t,arr[i]);
		Xuat1DG(temp->data,tungdo+=2);
	}
}
void XuatDG1Page_TenHo(TREE_DG t,DG *arr,int index,int tungdo )
{
	int soDG1Page=20;
	int soDG=countDG(t);
	tungdo=2;
	NODE_DG*temp=NULL;	
	index--;
	for(int i=0+soDG1Page*index;i<(soDG1Page+soDG1Page*index)&&i<soDG;i++)
	{
		temp=Find_DG(t,arr[i].maThe);
		Xuat1DG(temp->data,tungdo+=2);
	}
}
void XuatDSDG_MADG(TREE_DG t)
{
	int soDG1Page=20;
	ShowCur(false);
	int n = countDG(t);
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (n / soDG1Page) + 1;
	int tungdo=0;
	int index=0;
	int *arr = new int[n];
	Arr_To_Tree_MaDG(t,arr,index);
	VeKhungDG();
	XuatDG1Page(t, arr, tttrang,tungdo);
	int c;
	do
	{
	
		if (_kbhit())
		{
			c = _getch();
			if (c == 224 || c == 0)
				c = _getch();
			switch (c)
			{
			case LEFT:
				Xoa_ManHinh_DG();
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				XuatDG1Page(t,arr, tttrang,tungdo);
				break;

			case RIGHT:
				Xoa_ManHinh_DG();
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				XuatDG1Page(t,arr, tttrang,tungdo);
				break;
			case  27:
				return;
			}
		}
		ShowCur(false);
		gotoxy(80, 46);
		SetColor(4);
		cout << "HotKey: KEY LEFT, KEY RIGHT, ESC:THOAT";
		gotoxy(88, 45);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}while(true);
}
void XuatDSDG_HOTEN(TREE_DG t)
{
	int soDG1Page=20;
	ShowCur(false);
	int n = countDG(t);
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (n / soDG1Page) + 1;
	int tungdo=0;
	int index=0;
	DG *arr = new DG[n];
	Tree_To_Arr(t,arr,index);
	Sort_DG_TheoHOTEN(arr,index);
	VeKhungDG();
	XuatDG1Page_TenHo(t, arr, tttrang,tungdo);
	int c;
	do
	{
	
		if (_kbhit())
		{
			c = _getch();
			if (c == 224 || c == 0)
				c = _getch();
			switch (c)
			{
			case LEFT:
				Xoa_ManHinh_DG();
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				XuatDG1Page_TenHo(t,arr, tttrang,tungdo);
				break;

			case RIGHT:
				Xoa_ManHinh_DG();
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				XuatDG1Page_TenHo(t,arr, tttrang,tungdo);
				break;
			case  27:
				return;
			}
		}
		ShowCur(false);
		gotoxy(80, 46);
		SetColor(4);
		cout << "HotKey: KEY LEFT, KEY RIGHT, ESC:THOAT";
		gotoxy(88, 45);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}while(true);
}
int XuatDSDG_MADG_Xoa(TREE_DG t,int &kt1)
{
	Normal();
	int soDG1Page=20;
	ShowCur(false);
	int n = countDG(t);
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (n / soDG1Page) + 1;
	int tungdo=0;
	int index=0;
	int *arr = new int[n];
	Arr_To_Tree_MaDG(t,arr,index);
	int maDG;
	VeKhungDG();
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	XuatDG1Page(t, arr, tttrang,tungdo);
	int c;
	do
	{
	
		if (_kbhit())
		{
			c = _getch();
			switch (c)
			{
			case 13:
				BoxNhapMaDG();
				gotoxy(175,3);
				kt1 = NhapMaDocGia(maDG);
				return maDG;		
			case LEFT:
				Xoa_ManHinh_DG();
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				XuatDG1Page(t,arr, tttrang,tungdo);
				break;

			case RIGHT:
				Xoa_ManHinh_DG();
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				XuatDG1Page(t,arr, tttrang,tungdo);
				break;
			case  27:
				return -1;
			}
		}
		ShowCur(false);
		gotoxy(80, 46);
		SetColor(4);
		cout << "HotKey: KEY LEFT, KEY RIGHT, ESC:THOAT";
		gotoxy(88, 45);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}while(true);
}
void XoaDG(TREE_DG &t)
{
	Normal();
	int kt1; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	int dem;
	bool check=false;
XoaDG:
	gotoxy(175,3);cout<<"                  ";
	int maDG =XuatDSDG_MADG_Xoa(t,kt1);
	if(kt1==-1)
	{
		gotoxy(165,5);
		SetColor(4);
		cout<<"AN PHIM BAT KY DE THOAT";
		_getch();
		return;
	}
	if(maDG ==-1)
	{
		return;
	}
	else if (kt1==1)
	{
		temp=Find_DG(t,maDG);
		if(temp==NULL)
		{
			gotoxy(165,5);
			SetColor(4);
			cout<<"MA DG KHONG TON TAI";
			_getch();
			gotoxy(165,5);
			cout <<"                   ";
			XoaBoxNhapMaDG2();
			goto XoaDG;
		}
		else 
		{
			int temp1=SoSachDangMuon(temp->mt);
			if(temp1>0)
			{
				gotoxy(165,5);
				SetColor(4);
				cout<<"DG DANG MUON SACH KHONG THE XOA";
				_getch();
				gotoxy(165,5);
				cout <<"                               ";
				for(int i=0;i<4;i++)
				{
					gotoxy(165,1+i);cout<<"                             ";
				}
				XoaBoxNhapMaDG2();
				goto XoaDG;
			}
			else
			{
				gotoxy(165,10);cout<<"BAN CO MUON XOA DG KHONG?";
				gotoxy(165,11);cout<<"ENTER:DONG Y";
				gotoxy(180,11);cout<<"ESC: THOAT";
				while(kbhit)
				{
					int c=_getch();
					if(c==27)
					{
						gotoxy(165,10);cout<<"                          ";
						gotoxy(165,11);cout<<"             ";
						gotoxy(180,11);cout<<"             ";
						return;
					}	
					else if(c==13)
					{
						check=IsDeleted_DG(t,temp->data);
						gotoxy(165,5);
						SetColor(4);
						cout<<"XOA DG THANH CONG!";
						_getch();
						gotoxy(165,5);
						cout <<"                  ";
						gotoxy(165,10);cout<<"                          ";
						gotoxy(165,11);cout<<"             ";
						gotoxy(180,11);cout<<"             ";
						XoaBoxNhapMaDG2();
						Xoa_ManHinh_DG();
						goto XoaDG; 
					}
				}
			}
		
		}
	}
	
}
void ChinhSuaDG(TREE_DG &t)
{
	Normal();
	int kt1; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	int maDG=0;
	DG dg;
	int x=90;
	int y=20;
	int vitri=0;
HieuChinhDG:
	BoxNhapMaDG_MT();
	gotoxy(98,3);
	kt1 = NhapMaDocGia(maDG);
	if(kt1==-1)
	{
		gotoxy(85,5);
		SetColor(4);
		cout<<"BAN VUA HUY TAC VU HIEU CHINH DG AN 1 PHIM BAT KY DE TIEP TUC";
		_getch();
	}
	else if (kt1==1)
	{
		temp=Find_DG(t,maDG);
		if(temp==NULL)
		{
			gotoxy(85,5);
			SetColor(4);
			cout<<"MA DG KHONG TON TAI AN 1 PHIM BAT KY DE TIEP TUC";
			_getch();
			gotoxy(85,5);
			cout <<"                                                ";
			goto HieuChinhDG;
		}
	 else 
		{
			Box_Nhap_DG();
			string ho=temp->data.ho;
			string ten=temp->data.ten;
			int phai=temp->data.phai;
			int tinhtrang=temp->data.trangThaiThe;
			bool ESC=false;
			gotoxy(x+13,y+1);
			cout<<temp->data.maThe;
			while (true)
			{
				switch(vitri)
				{
				case 0: gotoxy(x+13,y+3);
						NhapHo(ho,vitri,ESC);
						break;
				case 1: gotoxy(x+13,y+5);
						NhapTen(ten,vitri,ESC);
						break;
				case 2: gotoxy(x+13,y+7);
						NhapPhai(phai,vitri,ESC);
						break;
				case 3: gotoxy(x+13,y+9);
						NhapTrangThai(tinhtrang,vitri,ESC);
						break;
				case 4: if(ho==""|| ten=="")
						{
							gotoxy(105,40);
							cout<<"CAC TRUONG DU LIEU KHONG DUOC DE TRONG!";
							vitri=0;
						}
						else 
						{
							Normal();
							gotoxy(95,32);
							cout<<"                                       ";
							ShowCur(false);
							gotoxy(95,32);
							cout<<"BAN CO MUON LUU DG HAY KHONG";
							gotoxy(95,33);
							cout<<"ENTER: LUU";
							gotoxy(110,33);
							cout<<"ESC: THOAT";	
							while(1)
							{
						
								int c=_getch();
								if(c==27)
								{
									ESC=true;
									return;
								}
								else if(c==13)
								{
									
									dg.ho=Chuan_Hoa_String(ho);
									dg.ten=Chuan_Hoa_String(ten);
									dg.phai=phai;
									dg.trangThaiThe=tinhtrang;
									temp->data.ho=dg.ho;
									temp->data.ten=dg.ten;
									temp->data.phai=dg.phai;
									temp->data.trangThaiThe=dg.trangThaiThe;
									gotoxy(95,32);
									cout<<"                                       ";
									gotoxy(95,33);
									cout<<"                                       ";
									gotoxy(95,33);
									SetColor(4);
									cout<<"LUU THANH CONG";
									Normal;
									Sleep(2000);
									return;
								}
							}
						}
				}
				if(ESC==true)
		{
			break;
		}
	}
				
		}
	}
	
}
void Load_DG(TREE_DG &t)
{
	// khoi tao cay doc gia
	initTREE_DG(t);
	fstream inFile;
	NODE_DG* pDG = NULL;
	DG dg;
	MT mt;
	inFile.open("DocGia.txt", ios::in);
	int sodocgia, sosachmuontra;

	if (inFile.is_open())
	{
		string temp;
		inFile >> sodocgia;

		for (int i = 0 ; i < sodocgia; i++)
		{
			inFile >> dg.maThe;
			inFile.ignore();
			getline(inFile, dg.ho,',');
			getline(inFile, dg.ten,',');
			inFile >> dg.phai;
			inFile.ignore();
			inFile >> dg.trangThaiThe;
			inFile.ignore();

			// them data vao cay doc gia.
			InsertDGtoTree(t, dg);
			pDG = Find_DG(t, dg.maThe);
			inFile >> sosachmuontra;
			getline(inFile, temp);
			for (int j = 0; j <  sosachmuontra; j++)
			{
				getline(inFile, mt.maSach,',');	
				getline(inFile, mt.tenSach,',');
				inFile >> mt.trangThai;inFile.ignore();
				inFile >> mt.ngayMuon.ngay;inFile.ignore();
				inFile >> mt.ngayMuon.thang;inFile.ignore();
				inFile >> mt.ngayMuon.nam;inFile.ignore();
				
				inFile >> mt.ngayTra.ngay;inFile.ignore();
				inFile >> mt.ngayTra.thang;inFile.ignore();
				inFile >> mt.ngayTra.nam;inFile.ignore();;
				// cap nhat du lieu vao
				ADD_head_MT(pDG->mt, mt);
			}
		}
	}
	else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}

	inFile.close();
}
void Save_1_DG(TREE_DG q,ofstream& fileout)
{
	if (q)
	{
		fileout << q->data.maThe << ',';
		fileout << q->data.ho << ',';
		fileout << q->data.ten << ',';
		fileout << q->data.phai << ',';
		fileout << q->data.trangThaiThe << endl;
		fileout << q->mt.n << endl;
		for (node_MT* p = q->mt.pHead; p != NULL; p = p->pNext)
		{
			fileout << p->data.maSach << ',';
			fileout << p->data.tenSach <<',';
			fileout << p->data.trangThai << ',';
			fileout << p->data.ngayMuon.ngay << '/';
			fileout << p->data.ngayMuon.thang << '/';
			fileout << p->data.ngayMuon.nam << ',';
			fileout << p->data.ngayTra.ngay << '/';
			fileout << p->data.ngayTra.thang << '/';
			fileout << p->data.ngayTra.nam << endl;
		}
		Save_1_DG(q->pLeft,fileout);
		Save_1_DG(q->pRight, fileout);
	}
}
void GHI_FILE_DS_DG(TREE_DG t)
{
	ofstream fileout;
	fileout.open("DocGia.txt", ios::out);
	if (fileout.is_open())
	{
		// so doc gia..
		fileout << countDG(t) << endl;
		Save_1_DG(t, fileout);
	}
	else
	{
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}
	fileout.close();
}
//=====================================Muon Tra===========================
void initList_MT(list_MT &lMT)
{
	lMT.pHead=lMT.pTail=NULL;
	lMT.n=0;
}
node_MT * GetNodeMT(MT mt)
{
	node_MT* p = new node_MT;
	if(p==NULL)
	{
		return NULL;
	}
	p->data=mt;
	p->pNext=NULL;
	//p->pPrev=NULL;
	return p;
}
void ADD_tail_MT(list_MT &lMT , MT mt)
{
	node_MT *p = GetNodeMT(mt);
	if (lMT.pHead == NULL)
	{
		lMT.pHead = lMT.pTail = p;
	}
	else
	{
		lMT.pTail->pNext = p;
		//p->pPrev = lMT.pTail;
		lMT.pTail = p;
	}
	lMT.n++;
}
void ADD_head_MT(list_MT &lMT , MT mt)
{
	node_MT *p = GetNodeMT(mt);
	if (lMT.pHead == NULL)
	{
		lMT.pHead = lMT.pTail = p;
	}
	else
	{
		//lMT.pHead->pPrev=p;
		p->pNext= lMT.pHead;
		lMT.pHead=p;
	}
	lMT.n++;
}
void XoaHienThi1()
{
	int x=5;
	int y=30;
	for(int i=0;i<10;i++)
	{
		gotoxy(x,y+i);
		cout<<"                   ";
	}
}
int DEM_SACH_DG_MUON(TREE_DG t)
{
	int so_sach_muon = 0;
	for (node_MT* p = t->mt.pHead; p != NULL; p=p->pNext)
	{
			so_sach_muon++;
	}
	return so_sach_muon;
}
void NhapTenSachCanTimKiem(string &kq,LIST_DAUSACH lDS)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	int demSpace=0;
	int vitritimthay=0;
	int tungdo=8;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// Ten sach  Chi Nhan Chu Thuong hoac Chu Hoa ,so, va Toi Da 35 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
			|| (c >=  48 && c <= 57) || c == 32) && demKitu < 30 && demKitu >= 0)
			{
				gotoxy(x,y);
				if(demSpace==1 && c==32)
				{
					demKitu++;
					cout << (char)c;
					kq += (char)c;
					demSpace = 0;
				}
				else if (c != 32)
				{
					demKitu++;
					cout << (char)c;
					kq += (char)c;
					demSpace = 1;
				}	
			}	
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			for(int i=0;i<lDS.n;i++)
			{
				vitritimthay=lDS.ListDS[i]->data.tenSach.find(kq);
				if(vitritimthay!=string::npos)
				{
					XuatDS(lDS.ListDS[i],tungdo+=2);
				}
			}	
		}
		
	}
}
int SoSachDangMuon(list_MT lMT)
{
	int i = 0;
	for (node_MT * p = lMT.pHead; p != NULL; p = p->pNext)
	{
		if (p->data.trangThai == 0 || p->data.trangThai == 2)
		{
			i++;
		}
	}
	return i;
}
string LayISBN_Tu_Masach(string masach)
{
	string temp="";
	for(int i=0;i<6;i++)
	{
		temp+=masach[i];
	}
	return temp;
}
int SearchDS_TheoMa(LIST_DAUSACH lDS, string maDS)
{
	for (int i = 0; i < lDS.n; i++)
	{
		if (lDS.ListDS[i]->data.ISBN==maDS)
			return i;
	}
	return -1;
}
node_DMS* SearchDMS_TheoMa(LIST_DAUSACH lDS, string maSach)
{
	string isbn = LayISBN_Tu_Masach(maSach);
	int index = SearchDS_TheoMa(lDS, isbn);
	if(index!=-1)
		for (node_DMS* p = lDS.ListDS[index]->dms.pHead; p != NULL; p = p->pNext)
		{
			if (p->data.maSach== maSach)
				return p;
		}
	return NULL;
}
bool KiemTra_Muon_Trung_DS(TREE_DG p, string ma_sach)
{
	string s = LayISBN_Tu_Masach(ma_sach);
	string temp;
	for (node_MT* q = p->mt.pHead; q != NULL; q=q->pNext)
	{
		if (q->data.trangThai == 0) //dang muon sach
		{
			temp = LayISBN_Tu_Masach(q->data.maSach);
			if (temp == s) // muon sach thuoc dau sach tuong tu
				return true;
		}
	}
	return false;
}
int SoNgayMuon_Max(list_MT lMT)
{
	int max = 0;
	int nngay;
	for (node_MT * p = lMT.pHead; p != NULL; p = p->pNext)
	{
		if ((p->data.trangThai == 0) || (p->data.trangThai == 2))
		{
			nngay = KhoangCachNgay(p->data.ngayMuon);
			if (max < nngay)
			{
				max = nngay;
			}
		}
	}
	return max;
}

int SoNgayQuaHan(list_MT lMT)
{
	int nNgayMuonMax = SoNgayMuon_Max(lMT);
	return nNgayMuonMax - 7;
}
void XuatDS_MT(MT mt, int tungdo)
{
	SetColor(4);
	gotoxy(45, 14);
	cout << "Ma Sach";
	gotoxy(60, 14);
	cout << "Ten Sach";
	gotoxy(100, 14);
	cout << "Ngay Muon";
	gotoxy(130, 14);
	cout << "Ngay Tra";
	gotoxy(160, 14);
	cout << "Trang Thai";
	Normal();
	gotoxy(45, tungdo);
	cout << mt.maSach;
	gotoxy(60, tungdo);
	cout << mt.tenSach;
	gotoxy(100, tungdo);
	cout << mt.ngayMuon.ngay << "/" << mt.ngayMuon.thang << "/" << mt.ngayMuon.nam;
	gotoxy(130, tungdo);
	cout << mt.ngayTra.ngay << "/" << mt.ngayTra.thang << "/" << mt.ngayTra.nam;
	gotoxy(160, tungdo);
	if (mt.trangThai == 0)
		cout << "DANG MUON";
	else if (mt.trangThai == 1)
		cout << "DA TRA";
	else
		cout << "LAM MAT";
}
int MenuDongMT(char td [][50],int so_item){
	int cot = 38;
	int dong = 16;
  int chon =0;
  int i; 
  HighLight();
  gotoxy(cot,dong+chon);
  cout << char(179);
  char kytu;
do {
  kytu = getch();
  if (kytu==-32) kytu = getch();
  switch (kytu) {
    case UP :if (chon >0)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon*2);cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon*2); 	cout << char(179);  				
  			  }
  			  break;
  	case DOWN :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon*2);	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon*2); 	cout <<char(179);
  				
  			  }
  			  break;
  	case 13 : Normal();
	  return chon+1;
  	case 27 : Normal();
	  return -1 ;
  }  // end switch
  } while (1);
}
void Muon_Sach(TREE_DG &t , LIST_DAUSACH &lDS)
{
	Normal();
	int kt1; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	int maDG=0;
	int dem;
	bool check1=false;
	bool check2=false;
MuonSach:
	BoxNhapMaDG_MT();
	gotoxy(98,3);
	kt1 = NhapMaDocGia(maDG);
	if(kt1==-1)
	{
		gotoxy(85,5);
		SetColor(4);
		cout<<"BAN VUA HUY MUON SACH AN 1 PHIM BAT KY DE TIEP TUC";
		_getch();
	}
	else if (kt1==1)
	{
		temp=Find_DG(t,maDG);
		if(temp==NULL)
		{
			gotoxy(85,5);
			SetColor(4);
			cout<<"MA DG KHONG TON TAI AN 1 PHIM BAT KY DE TIEP TUC";
			_getch();
			gotoxy(85,5);
			cout <<"                                               ";
			goto MuonSach;
		}
		else
		{
			ShowCur(false);
			gotoxy(90,6);cout<<"THONG TIN MT CUA DG";
			gotoxy(90,8);
			cout<<"Ho Va Ten: " <<temp->data.ho<<" "<<temp->data.ten;
			gotoxy(90, 9);
			cout << "Trang thai the : ";
			(temp->data.trangThaiThe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(90, 10);
			cout << "Phai: ";
			(temp->data.phai == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(90, 11);
			cout << "So sach  da muon : " << temp->mt.n;
			gotoxy(90, 12);
			cout << "So sach  dang muon : " << SoSachDangMuon(temp->mt);
			gotoxy(95, 14);
			cout << "___CAC SACH DANG MUON___";
			gotoxy(90, 15);
			cout << "__Ten Sach__________________________";
			gotoxy(120, 15);
			cout << "_Ngay Muon__";
			int i =  0; 
			for (node_MT * p = temp->mt.pHead; p != NULL ; p = p->pNext)
			{
				// truong hop dang muon chua tra, va truong hop dang muon nhung bi mat sach.
				if (p->data.trangThai == 0  || p->data.trangThai == 2)
				{
					// nap vao so sach muon cua doc gia qua bien i
					
					gotoxy(92 , 16 + i);    
					cout << "                                           ";
					gotoxy(92, 16+ i);
					cout << p->data.tenSach;
					gotoxy(120,16+i);
					cout<<p->data.ngayMuon.ngay <<"/"<<p->data.ngayMuon.thang<<"/"<<p->data.ngayMuon.nam;
					i++;
					if (i == 3)
					{
						SetColor(4);
						gotoxy(90,20);cout<<"DG dang muon 3 cuon sach ";
						_getch();
						Xoa1Khoang();
						Normal();
						goto MuonSach;
					}
				}
			}
			if(SoNgayMuon_Max(temp->mt)>7)
			{
				gotoxy(90,20);
				SetColor(4);   cout<<"DOC GIA DA MUON SACH QUA 7 NGAY!";
				getch();
				gotoxy(90,20); cout<<"                                 ";
				Normal();
				goto MuonSach;
			}
			if(temp->data.trangThaiThe==0)
			{
				gotoxy(90,20);
				SetColor(4);   cout<<"THE DG BI KHOA KHONG THE MUON SACH!";
				getch();
				gotoxy(90,20); cout<<"                                   ";
				Normal();
				goto MuonSach;
			}
	NhapMaSach:
			while(1)
			{
				ShowCur(true);
				gotoxy(90,21);
				SetColor(4);cout<<"HAY NHAP VAO MA SACH";
				Normal();
				gotoxy(90,22);
				BoxNhapMaSach();
				string masach="";
				string ISBN="";
				bool ESC=false;
				bool luu=false;
				gotoxy(100,23);
				NhapMaSach(masach,ESC,luu);
				masach=In_Hoa_String(masach);
				if(ESC==true)
				{
					Xoa1Khoang();
					goto MuonSach;
				}		
				ISBN=LayISBN_Tu_Masach(masach);
				int index=SearchDS_TheoMa(lDS,ISBN);
				if(index==-1)
				{
					SetColor(4);
					gotoxy(95,25);cout<<"MA SACH KHONG DUNG";
					getch();
					gotoxy(95,23);cout<<"                                 ";
					gotoxy(95,25);cout<<"                                 ";
					Normal();
				}
				else
				{
					if(KiemTra_Muon_Trung_DS(temp,masach))
					{
						SetColor(4);
						gotoxy(95,25);cout<<"DG DA MUON SACH NAY";
						getch();
						gotoxy(95,23);cout<<"                                 ";
						gotoxy(95,25);cout<<"                                 ";
						goto NhapMaSach;
						Normal();
					}
					node_DMS * sach =SearchDMS_TheoMa(lDS,masach);
					SetColor(4);
					gotoxy(95,25);cout<<"THONG TIN SACH";
					Normal();
					if(sach==NULL)
					{
						SetColor(4);
						gotoxy(95,25);cout<<"MA SACH KHONG DUNG";
						getch();
						gotoxy(95,23);cout<<"                                 ";
						gotoxy(95,25);cout<<"                                 ";
						Normal();
						XoaThongTinSach();
						goto NhapMaSach;
					}
					else
					{
						gotoxy(90,26);cout<<"MA SACH:"<<sach->data.maSach;
						gotoxy(90,27);cout<<"TEN SACH: " << lDS.ListDS[index]->data.tenSach;
						gotoxy(90,28);cout<<"TRANG THAI SACH:";
						if(sach->data.trangThaiSach==0)
						{
							cout<<"CHO MUON DUOC";
						}
						else if(sach->data.trangThaiSach==1)
						{
							cout<<"DA DUOC MUON";
						}
						else if(sach->data.trangThaiSach==2)
						{
								cout<<"DA THANH LY";
						}
						gotoxy(90,30);cout<<"BAN CO MUON MUON SACH NAY KHONG?";
						SetColor(4);
						gotoxy(90,32);cout<<"ENTER: DONG Y";
						gotoxy(110,32);cout<<"ESC:THOAT";
						Normal();
					}
					
					while(kbhit)
					{
						int c=getch();
						if(c==13)
						{
							break;
						}
						else if(c==27)
						{
							gotoxy(95,23);cout<<"                                 ";
							gotoxy(95,25);cout<<"                                 ";
							XoaThongTinSach();
							goto NhapMaSach;
						}
					}
					gotoxy(90,30);cout<<"                                    ";
					gotoxy(90,32);cout<<"                    ";
					gotoxy(110,32);cout<<"             ";
					for (node_DMS* k = lDS.ListDS[index]->dms.pHead; k != NULL; k = k->pNext)
					{
						if (k->data.maSach == masach)
						{
							check2=true;
							if (k->data.trangThaiSach == 0)
							{
								check1 = true; 
								// danh dau tim thay sach
								k->data.trangThaiSach = 1; // cap nhat sach co nguoi muon
								break;
							}
							else if (k->data.trangThaiSach == 1)
							{
								SetColor(4);
								gotoxy(95,33);cout<<"SACH DA CO NGUOI MUON";
								getch();
								gotoxy(95,23);cout<<"                                 ";
								gotoxy(95,25);cout<<"                                 ";
								Normal();
								XoaThongTinSach();
								goto NhapMaSach;
							}
							else if (k->data.trangThaiSach)
							{
								SetColor(4);
								gotoxy(95,33);cout<<"SACH DA THANH LY";
								getch();
								gotoxy(95,23);cout<<"                                 ";
								gotoxy(95,25);cout<<"                                 ";
								Normal();
								XoaThongTinSach();
								goto NhapMaSach;
							}
							
						}
					}
					if (check2==false)
					{
						SetColor(4);
						gotoxy(95,25);cout<<"MA SACH KHONG DUNG";
						getch();
						gotoxy(95,23);cout<<"                                 ";
						gotoxy(95,25);cout<<"                                 ";
						Normal();
						XoaThongTinSach();
					}
					else
					{
						MT x;
						x.maSach=masach;
						thoi_gian_thuc(x.ngayMuon);
						x.ngayTra.ngay = 0;
						x.ngayTra.thang = 0;
						x.ngayTra.nam = 0;
						x.trangThai = 0;
						x.tenSach=lDS.ListDS[index]->data.tenSach;
						ADD_tail_MT(temp->mt,x);
						lDS.ListDS[index]->data.soLuongMuon++;
						SetColor(4);
						gotoxy(95,33);cout<<"MUON THANH CONG";
						getch();
						return;
						Normal();
					}
				}
			}
		}
	}	
}
void TraSach(TREE_DG &t, LIST_DAUSACH &lDS)
{
	Normal();
	int kt1; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	int maDG=0;
	int dem;
	bool check1=false;
	bool check2=false;
TraSach:
	BoxNhapMaDG_MT();
	gotoxy(98,3);
	kt1 = NhapMaDocGia(maDG);
	if(kt1==-1)
	{
		gotoxy(85,5);
		SetColor(4);
		cout<<"BAN VUA HUY MUON SACH AN 1 PHIM BAT KY DE TIEP TUC";
		_getch();
	}
	else if (kt1==1)
	{
		temp=Find_DG(t,maDG);
		if(temp==NULL)
		{
			gotoxy(85,5);
			SetColor(4);
			cout<<"MA DG KHONG TON TAI AN 1 PHIM BAT KY DE TIEP TUC";
			_getch();
			gotoxy(85,5);
			cout <<"                                               ";
			goto TraSach;
		}
		else
		{
			gotoxy(90,6);cout<<"THONG TIN MT CUA DG";
			gotoxy(90,8);
			cout<<"Ho Va Ten: " <<temp->data.ho<<" "<<temp->data.ten;
			gotoxy(90, 9);
			cout << "Trang thai the : ";
			(temp->data.trangThaiThe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(90, 10);
			cout << "Phai: ";
			(temp->data.phai == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(90, 11);
			cout << "So sach  da muon : " << temp->mt.n;
			gotoxy(90, 12);
			cout << "So sach  dang muon : " << SoSachDangMuon(temp->mt);
			int n =SoSachDangMuon(temp->mt);

			MT *arr = new MT[n];
			int i =0;
			int tungdo=0;
			for(node_MT *p = temp->mt.pHead;p!=NULL;p=p->pNext)
			{
				if(p->data.trangThai==0||p->data.trangThai==2)//0 la dang muon , 2 la mat sach
				{
					check1=true;
					node_DMS *sach=SearchDMS_TheoMa(lDS,p->data.maSach);
					string isbn = LayISBN_Tu_Masach(sach->data.maSach);
					int index= SearchDS_TheoMa(lDS,isbn);
					if(index!=-1)
					{
						XuatDS_MT(p->data,16+tungdo);
						arr[i++]=p->data;
						tungdo+=2;
					}
				}
			}
			ShowCur(false);
			int index1=MenuDongMT(td,n);
			
			if( index1==-1)
			{
				Xoa1Khoang();
				goto TraSach;
			}
			else
			{
				ShowCur(true);
				Ngay_Thang n1;
				thoi_gian_thuc(n1);
				node_DMS* sach1 = SearchDMS_TheoMa(lDS, arr[index1 - 1].maSach);
				for (node_MT* p = temp->mt.pHead; p != NULL; p = p->pNext)
				{
					if (p->data.maSach == sach1->data.maSach)
					{
						sach1->data.trangThaiSach = 0; // cap nhat sach co the muon
						p->data.trangThai=1;
						p->data.ngayTra = n1;
					}
					
				}
				gotoxy(95,25);
				SetColor(4);
				cout<<"TRA SACH THANH CONG!";
				getch();
			}		
		}	
	}
}
void MatSach(TREE_DG &t, LIST_DAUSACH &lDS)
{
	Normal();
	int kt1; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	int maDG=0;
	int dem;
	bool check1=false;
	bool check2=false;
MatSach:
	BoxNhapMaDG_MT();
	gotoxy(98,3);
	kt1 = NhapMaDocGia(maDG);
	if(kt1==-1)
	{
		gotoxy(85,5);
		SetColor(4);
		cout<<"BAN VUA HUY MUON SACH AN 1 PHIM BAT KY DE TIEP TUC";
		_getch();
	}
	else if (kt1==1)
	{
		temp=Find_DG(t,maDG);
		if(temp==NULL)
		{
			gotoxy(85,5);
			SetColor(4);
			cout<<"MA DG KHONG TON TAI AN 1 PHIM BAT KY DE TIEP TUC";
			_getch();
			gotoxy(85,5);
			cout <<"                                               ";
			goto MatSach;
		}
		else
		{
			gotoxy(90,6);cout<<"THONG TIN MT CUA DG";
			gotoxy(90,8);
			cout<<"Ho Va Ten: " <<temp->data.ho<<" "<<temp->data.ten;
			gotoxy(90, 9);
			cout << "Trang thai the : ";
			(temp->data.trangThaiThe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(90, 10);
			cout << "Phai: ";
			(temp->data.phai == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(90, 11);
			cout << "So sach  da muon : " << temp->mt.n;
			gotoxy(90, 12);
			cout << "So sach  dang muon : " << SoSachDangMuon(temp->mt);
			int n =SoSachDangMuon(temp->mt);

			MT *arr = new MT[n];
			int i =0;
			int tungdo=0;
			for(node_MT *p = temp->mt.pHead;p!=NULL;p=p->pNext)
			{
				if(p->data.trangThai==0)//0 la dang muon
				{
					check1=true;
					node_DMS *sach=SearchDMS_TheoMa(lDS,p->data.maSach);
					string isbn = LayISBN_Tu_Masach(sach->data.maSach);
					int index= SearchDS_TheoMa(lDS,isbn);
					if(index!=-1)
					{
						XuatDS_MT(p->data,16+tungdo);
						arr[i++]=p->data;
						tungdo+=2;
					}
				}
			}
			ShowCur(false);
			int index1=MenuDongMT(td,n);
			
			if( index1==-1)
			{
				Xoa1Khoang();
				goto MatSach;
			}
			else
			{
				ShowCur(true);
				Ngay_Thang n1;
				thoi_gian_thuc(n1);
				node_DMS* sach1 = SearchDMS_TheoMa(lDS, arr[index1 - 1].maSach);
				for (node_MT* p = temp->mt.pHead; p != NULL; p = p->pNext)
				{
					if (p->data.maSach == sach1->data.maSach)
					{
						sach1->data.trangThaiSach = 2; // cap nhat sach co the muon
						p->data.trangThai=2;
					}
					
				}
				gotoxy(95,25);
				SetColor(4);
				cout<<"BAO MAT SACH THANH CONG!";
				getch();
			}		
		}	
	}
}
void top10sach(LIST_DAUSACH lDS)
{
	pDAU_SACH temp = NULL;
	for (int i = 0; i < lDS.n - 1; i++)
	{
		for (int j = i + 1; j < lDS.n; j++)
		{
			if (lDS.ListDS[i]->data.soLuongMuon < lDS.ListDS[j]->data.soLuongMuon)
			{
				temp = lDS.ListDS[i];
				lDS.ListDS[i] = lDS.ListDS[j];
				lDS.ListDS[j] = temp;
			}

		}
	}
	Box_Xuat_DS_Top10();
	int tungdo=4;
	for (int k = 0; k < lDS.n && k < 10; k++)
	{
		XuatDS(lDS.ListDS[k], tungdo );
		gotoxy(170, tungdo); cout << "     ";
		gotoxy(170, tungdo); Normal(); cout << lDS.ListDS[k]->data.soLuongMuon;
		tungdo+=2;
	}
}
void DS_QUAHAN(TREE_DG t)
{
	Normal();
	int n1 = countDG(t);//so luong dg toi da
	QUAHAN* arr = new QUAHAN[n1];
	int n = 0; // 
	TREE_DG* Stack = new NODE_DG * [n1];
	int so_ngay = 0; // 
	int sp = -1;//khai bao stack rong
	TREE_DG t1 = t; // luu lai node goc truoc khi duyet
	do
	{
		while (t != NULL)
		{
			Stack[++sp] = t; // push
			t = t->pLeft;
		}
		if (sp != -1)// neu stack khong rong moi thuc hien lenh pop
		{
			t = Stack[sp--]; // pop
			for (node_MT* p = t->mt.pHead; p != NULL; p = p->pNext)
			{
				// DANG MUON SACH
				if (p->data.trangThai == 0 || p->data.trangThai == 2) {
					so_ngay = KhoangCachNgay(p->data.ngayMuon);
					if (so_ngay >= 7)
					{
						n++;
						arr[n - 1].maDG = t->data.maThe;
						arr[n - 1].maSach = p->data.maSach;
						arr[n - 1].soNgayQH = so_ngay-7;
						arr[n - 1].tenSach = p->data.tenSach;
					}
				}
			}
			t = t->pRight;
		}
		else break;
	} while (1);
	delete[] Stack;
	QUAHAN temp;
	// sap xep giam dan ds qua han
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].soNgayQH < arr[j].soNgayQH)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	bool check = false;
	TREE_DG p = NULL;
	node_MT* q = NULL;
	int tungdo=2;
	// xuat ds qua han theo thu tu giam dan
	for (int k = 0; k < n; k++)
	{
		p = Find_DG(t1, arr[k].maDG);
		for (q = p->mt.pHead; q != NULL; q = q->pNext)
			if (q->data.maSach == arr[k].maSach) break;
		check = true;
		SetColor(4);
		gotoxy(40, 1);
		cout << "MA THE";
		gotoxy(55, 1);
		cout << "HO";
		gotoxy(70, 1);
		cout << "TEN";
		gotoxy(85, 1);
		cout << "PHAI";
		gotoxy(100, 1);
		cout << "MA SACH";
		gotoxy(110, 1);
		cout << "TEN SACH";
		gotoxy(155, 1);
		cout << "NGAY MUON";
		gotoxy(175,1);
		cout<<"SO NGAY QH";
		Normal();
		gotoxy(40, tungdo + 1);
		cout << arr[k].maDG;
		gotoxy(55, tungdo + 1);
		cout << p->data.ho;
		gotoxy(70, tungdo + 1);
		cout << p->data.ten;
		gotoxy(85, tungdo + 1);
		if(p->data.phai==0)
		{
			cout<<"NAM";
		}
		else if(p->data.phai==1)
		{
			cout<<"NU";
		}
		gotoxy(100, tungdo + 1);
		cout << arr[k].maSach;
		gotoxy(110, tungdo + 1);
		cout << arr[k].tenSach;
		gotoxy(155, tungdo + 1);
		cout << q->data.ngayMuon.ngay << "/" << q->data.ngayMuon.thang << "/" << q->data.ngayMuon.nam;
		gotoxy(175, tungdo + 1);
		cout << arr[k].soNgayQH;
		tungdo+=1;
	}
		_getch();
	delete[] arr;
}
void DanhSachCacSachDangMuon(TREE_DG t, LIST_DAUSACH lDS)
{
	Normal();
	int kt1; // bieesn kiem tra ESC cua ham nhap
	int tungdo = 0;
	TREE_DG temp = NULL;// luu  dc gi t?m duc
	int maDG=0;
	int dem;
	bool check1=false;
	bool check2=false;
XuatMT:
	BoxNhapMaDG_MT();
	gotoxy(98,3);
	kt1 = NhapMaDocGia(maDG);
	if(kt1==-1)
	{
		gotoxy(85,5);
		SetColor(4);
		cout<<"BAN VUA HUY MUON SACH AN 1 PHIM BAT KY DE TIEP TUC";
		_getch();
	}
	else if (kt1==1)
	{
		temp=Find_DG(t,maDG);
		if(temp==NULL)
		{
			gotoxy(85,5);
			SetColor(4);
			cout<<"MA DG KHONG TON TAI AN 1 PHIM BAT KY DE TIEP TUC";
			_getch();
			gotoxy(85,5);
			cout <<"                                               ";
			goto XuatMT;
		}
		else
		{
			gotoxy(90,6);cout<<"THONG TIN MT CUA DG";
			gotoxy(90,8);
			cout<<"Ho Va Ten: " <<temp->data.ho<<" "<<temp->data.ten;
			gotoxy(90, 9);
			cout << "Trang thai the : ";
			(temp->data.trangThaiThe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(90, 10);
			cout << "Phai: ";
			(temp->data.phai == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(90, 11);
			cout << "So sach  da muon : " << temp->mt.n;
			gotoxy(90, 12);
			cout << "So sach  dang muon : " << SoSachDangMuon(temp->mt);
			int n =SoSachDangMuon(temp->mt);
			MT *arr = new MT[n];
			int i =0;
			int tungdo=0;
			for(node_MT *p = temp->mt.pHead;p!=NULL;p=p->pNext)
			{
				if(p->data.trangThai==0||p->data.trangThai==2)//0 la dang muon , 2 la mat sach
				{
					check1=true;
					node_DMS *sach=SearchDMS_TheoMa(lDS,p->data.maSach);
					string isbn = LayISBN_Tu_Masach(sach->data.maSach);
					int index= SearchDS_TheoMa(lDS,isbn);
					if(index!=-1)
					{
						XuatDS_MT(p->data,16+tungdo);
						arr[i++]=p->data;
						tungdo+=2;
					}
				}
			}
			ShowCur(false);
			getch();
	}
}
}

