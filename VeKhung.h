#pragma once
#include "KiemTraNhap.h"
#define Box_XuatDS_Size_X 120
#define Box_XuatDS_Size_Y 43
using namespace std;
void Normal () 
{
	SetColor(0);
	SetBGColor(15);
}
void HighLight () 
{
	SetColor(15);
	SetBGColor(2);
}
void Box_Xuat_DS()
{
	Normal();
	int x=39;
	int y=1;
	int Box_size_x=120;
	int Box_size_y=42;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+7,y);cout<<char(194);
	gotoxy(x+7+40,y);cout<<char(194);
	gotoxy(x+7+40+10,y);cout<<char(194);
	gotoxy(x+7+40+10+40,y);cout<<char(194);
	gotoxy(x+7+40+10+40+8,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+7,y+i);
		cout<<char(179);
		gotoxy(x+7+40,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10+40,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10+40+8,y+i);
		cout<<char(179);
		gotoxy(x+Box_size_x+1,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+7,y+i);
		cout<<char(197);
		gotoxy(x+7+40,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10+40,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10+40+8,y+i);
		cout<<char(197);
	}
	gotoxy(x+7,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10+40,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10+40+8,y+Box_size_y);
	cout << char(193);
	SetColor(4);
	gotoxy(x+1,y+1);
	cout<< "ISBN";
	gotoxy(x+8,y+1);
	cout<<"TEN SACH";
	gotoxy(x+8+40,y+1);
	cout<<"SO TRANG";
	gotoxy(x+8+40+10,y+1);
	cout<<"TAC GIA";
	gotoxy(x+8+40+10+40,y+1);
	cout<<"NAM XB";
	gotoxy(x+8+40+10+40+8,y+1);
	cout<<"THE LOAI";
	Normal();
}
void Xoa_Man_Hinh_DS()
{
	for (int i =4 ;i<Box_XuatDS_Size_Y;i+=2)
	{
		gotoxy(40,i);cout<<"      ";
		gotoxy(47,i);cout<<"                                       ";
		gotoxy(87,i);cout<<"         ";
		gotoxy(97,i);cout<<"                                       ";
		gotoxy(137,i);cout<<"       ";
		gotoxy(145,i);cout<<"               ";
	}
}
void Ve_Background()
{
	gotoxy(0,0);
	SetBGColor(3);
	cout<<"                                                                                                                                                                                                        ";
	gotoxy(0,49);
	SetBGColor(3);
	cout<<"                                                                                                                                                                                                        ";
	Normal();
	for(int i=0;i<50;i++)
	{
		gotoxy(0,i);
		SetBGColor(3);
		cout<<" ";	
	}
	for(int i=0;i<50;i++)
	{
		gotoxy(199,i);
		SetBGColor(3);
		cout<<" ";	
	}
	for(int i=0;i<50;i++)
	{
		gotoxy(35,i);
		SetBGColor(3);
		cout<<" ";
	}
	gotoxy(0,27);
	SetBGColor(3);
	cout<<"                                   ";
	// Huong Dan
	SetColor(4);
	gotoxy(8,30);
	cout<<"HUONG DAN";
	gotoxy(5,32);cout<<"<- , -> : ";
	gotoxy(5,33);cout<<"ENTER:    ";
	gotoxy(5,34);cout<<"ESC:      ";
	Normal();
	gotoxy(15,32);cout<<"CHUYEN TRANG";
	gotoxy(15,33);cout<<"XAC NHAN";
	gotoxy(15,34);cout<<"THOAT";
}
void VeBoxNhapDS()
{
	Normal();
	int x=90;
	int y=20;
	int Box_size_x=50;
	int Box_size_y=12;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+12,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+12,y+i);
		cout<<char(179);
		gotoxy(x+Box_size_x+1,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+12,y+i);
		cout<<char(197);
	}
	gotoxy(x+12,y+Box_size_y);
	cout<<char(193);
	SetColor(2);
	gotoxy(x+1,y+1);
	cout<<"ISBN       ";
	gotoxy(x+1,y+3);
	cout<<"TEN SACH   ";
	gotoxy(x+1,y+5);
	cout<<"SO TRANG   ";
	gotoxy(x+1,y+7);
	cout<<"TAC GIA    ";
	gotoxy(x+1,y+9);
	cout<<"NAM XB     ";
	gotoxy(x+1,y+11);
	cout<<"THE LOAI   ";
	gotoxy(x+13,y-1);
	HighLight();
	cout<<"BOX NHAP VAO DAU SACH";
}
void Phong_To_Ho()
{
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
}
void Box_Nhap_DG()
{
	int x=90;
	int y=20;
	int Box_size_x=50;
	int Box_size_y=10;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+12,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+12,y+i);
		cout<<char(179);
		gotoxy(x+Box_size_x+1,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+12,y+i);
		cout<<char(197);
	}
	gotoxy(x+12,y+Box_size_y);
	cout<<char(193);
	gotoxy(x+1,y+1);
	SetColor(4);
	cout<<"MA THE     ";
	gotoxy(x+1,y+3);
	cout<<"HO         ";
	gotoxy(x+1,y+5);
	cout<<"TEN        ";
	gotoxy(x+1,y+7);
	cout<<"PHAI       ";
	gotoxy(x+1,y+9);
	cout<<"TINH TRANG ";
}
void VeKhungDG()
{
	
	int x=75;
	int y=1;
	int Box_size_x=80;
	int Box_size_y=42;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+12,y);cout<<char(194);
	gotoxy(x+12+30,y);cout<<char(194);
	gotoxy(x+12+30+15,y);cout<<char(194);
	gotoxy(x+12+30+15+7,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+12,y+i);
		cout<<char(179);
		gotoxy(x+12+30,y+i);
		cout<<char(179);
		gotoxy(x+12+30+15,y+i);
		cout<<char(179);
		gotoxy(x+12+30+15+7,y+i);
		cout<<char(179);
		gotoxy(x+Box_size_x+1,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+12,y+i);
		cout<<char(197);
		gotoxy(x+12+30,y+i);
		cout<<char(197);
		gotoxy(x+12+30+15,y+i);
		cout<<char(197);
		gotoxy(x+12+30+15+7,y+i);
		cout<<char(197);
	}
	gotoxy(x+12,y+Box_size_y);
	cout << char(193);
	gotoxy(x+12+30,y+Box_size_y);
	cout << char(193);
	gotoxy(x+12+30+15,y+Box_size_y);
	cout << char(193);
	gotoxy(x+12+30+15+7,y+Box_size_y);
	cout << char(193);
	SetColor(4);
	gotoxy(x+3,y+1);
	cout<< "MA THE";
	gotoxy(x+22,y+1);
	cout<<"HO DOC GIA";
	gotoxy(x+44,y+1);
	cout<<"TEN DOC GIA";
	gotoxy(x+59,y+1);
	cout<<"PHAI";
	gotoxy(x+66,y+1);
	cout<<"TRANG THAI THE";
	Normal();
}
void Xoa_ManHinh_DG()
{
	int x=75;
	int y=1;
	int Box_size_x=80;
	int Box_size_y=42;
	for(int i=3;i<Box_size_y;i+=2)
	{
		gotoxy(x+1,y+i);cout<<"           ";
		gotoxy(x+13,y+i);cout<<"                             ";
		gotoxy(x+43,y+i);cout<<"              ";
		gotoxy(x+43+15,y+i);cout<<"      ";
		gotoxy(x+43+15+7,y+i);cout<<"                ";
		
	}
}
void Xoa1Khoang()
{
 	int x=38;
 	int y= 1;
 	for (int i=0;i<45;i++)
 	{
 		gotoxy(x,y+i);
 		cout <<"                                                                                                                                                                ";
	 }
}
void Xoa1Khoang2()
{
 	int x=38;
 	int y= 1;
 	for (int i=0;i<45;i++)
 	{
 		gotoxy(x,y+i);
 		cout <<"                                                                                                                       ";
	 }
}
void BoxNhapMaDG()
{
	Normal();
	int x=165;
	int y=1;
	int Box_size_x=30;
	gotoxy(x,y);
	SetColor(4);
	cout<<"HAY NHAP VAO MA DG CAN MUON SACH";
	Normal();
	gotoxy(x,y+1);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	gotoxy(x,y+2);cout<<char(179);
	gotoxy(x+Box_size_x+1,y+2);cout<<char(179);
	gotoxy(x+1,y+2);cout<<"MA DG:";
	gotoxy(x,y+3);cout<<char(192);
	gotoxy(x+Box_size_x+1,y+3);cout<<char(217);
	gotoxy(x+1,y+3);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
}
void BoxNhapMaDG_MT()
{
	Normal();
	int x=90;
	int y=1;
	int Box_size_x=30;
	gotoxy(x,y);
	SetColor(4);
	cout<<"HAY NHAP VAO MA DG CAN MUON SACH";
	Normal();
	gotoxy(x,y+1);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	gotoxy(x,y+2);cout<<char(179);
	gotoxy(x+Box_size_x+1,y+2);cout<<char(179);
	gotoxy(x+1,y+2);cout<<"MA DG:";
	gotoxy(x,y+3);cout<<char(192);
	gotoxy(x+Box_size_x+1,y+3);cout<<char(217);
	gotoxy(x+1,y+3);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
}
void XoaBoxNhapMaDG()
{
	Normal();
	int x=90;
	int y=1;
	for(int i=0;i<4;i++)
	{
		gotoxy(x,y+i);
		cout<<"                                  ";
	}
}
void XoaBoxNhapMaDG2()
{
	Normal();
	int x=165;
	int y=1;
	for(int i=0;i<4;i++)
	{
		gotoxy(x,y+i);
		cout<<"                                  ";
	}
}
void BoxNhapTenSach()
{
	Normal();
	int x=90;
	int y=1;
	int Box_size_x=30;
	gotoxy(x,y);
	SetColor(4);
	cout<<"HAY NHAP VAO TEN SACH MUON MUON";
	Normal();
	gotoxy(x,y+1);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	gotoxy(x,y+2);cout<<char(179);
	gotoxy(x+Box_size_x+1,y+2);cout<<char(179);
	gotoxy(x+1,y+2);cout<<"TEN SACH:";
	gotoxy(x,y+3);cout<<char(192);
	gotoxy(x+Box_size_x+1,y+3);cout<<char(217);
	gotoxy(x+1,y+3);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
}
void BoxNhapSach()
{
	Normal();
	int x=80;
	int y=5;
	int Box_size_x=50;
	int Box_size_y=6;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+12,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+12,y+i);
		cout<<char(179);
		gotoxy(x+Box_size_x+1,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+12,y+i);
		cout<<char(197);
	}
	gotoxy(x+12,y+Box_size_y);
	cout<<char(193);
	SetColor(2);
	gotoxy(x+1,y+1);
	cout<<"MA SACH   ";
	gotoxy(x+1,y+3);
	cout<<"VI TRI    ";
	gotoxy(x+1,y+5);
	cout<<"TRANG THAI";
	
}
void XoaBoxNhapSach()//xoa cac field thong tin
{
	int x=95;
	int y=6;
	for(int i=0;i<3;i+=2)
	{
		gotoxy(x,y+i);
		cout<<"                             ";
	}
}
void XoaBoxNhapSach2() // Xoa Ca Khung Va TT sach
{
	int x=80;
	int y=4;
	for(int i=0;i<8;i+=1)
	{
		gotoxy(x,y+i);
		cout<<"                                                                         ";
	}
}
void BoxNhapMaSach()
{
	int x=wherex();
	int y=wherey();
	gotoxy(x,y);cout<<char(218);
	int Box_size_x=30;
	int i;
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x,y+1);cout<<char(179);
	gotoxy(x+Box_size_x+1,y+1);cout<<char(179);
	gotoxy(x+1,y+1);cout<<"MA SACH:";
	gotoxy(x,y+2);cout<<char(192);
	gotoxy(x+Box_size_x+1,y+2);cout<<char(217);
	gotoxy(x+1,y+2);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
}
void VeKhungDMS()
{
	
	int x=39;
	int y=1;
	int Box_size_x=80;
	int Box_size_y=42;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+12,y);cout<<char(194);
	gotoxy(x+12+30,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+12,y+i);
		cout<<char(179);
		gotoxy(x+12+30,y+i);
		cout<<char(179);
		gotoxy(x+12+30+39,y+i);cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+12,y+i);
		cout<<char(197);
		gotoxy(x+12+30,y+i);
		cout<<char(197);
	}
	gotoxy(x+12,y+Box_size_y);
	cout << char(193);
	gotoxy(x+12+30,y+Box_size_y);
	cout << char(193);
	SetColor(4);
	gotoxy(x+3,y+1);
	cout<< "MA SACH";
	gotoxy(x+20,y+1);
	cout<<"TRANG THAI SACH";
	gotoxy(x+60,y+1);
	cout<<"VI TRI";
	Normal();
}
void XoaKhungDMS()
{
	int x=40;
	int y=3;
	int Box_size_x=80;
	int Box_size_y=40;
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);cout<<"           ";
		gotoxy(x+12,y+i);cout<<"                             ";
		gotoxy(x+42,y+i);cout<<"                                      ";	
	}
	
}
void Box_NhapSachTimKiem()
{
	Normal();
	int x=165;
	int y=1;
	int Box_size_x=30;
	gotoxy(x,y);
	SetColor(4);
	cout<<"HAY NHAP VAO MA DG CAN MUON SACH";
	Normal();
	gotoxy(x,y+1);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	gotoxy(x,y+2);cout<<char(179);
	gotoxy(x+Box_size_x+1,y+2);cout<<char(179);
	gotoxy(x+1,y+2);cout<<"TEN SACH:";
	gotoxy(x,y+3);cout<<char(192);
	gotoxy(x+Box_size_x+1,y+3);cout<<char(217);
	gotoxy(x+1,y+3);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
}
void Box_Xuat_DS_Top10()
{
	Normal();
	int x=39;
	int y=1;
	int Box_size_x=140;
	int Box_size_y=42;
	gotoxy(x,y);cout<<char(218);
	for(int i=0;i<Box_size_x;i++)
	{
		cout<<char(196);
	}
	cout << char(191);
	gotoxy(x+7,y);cout<<char(194);
	gotoxy(x+7+40,y);cout<<char(194);
	gotoxy(x+7+40+10,y);cout<<char(194);
	gotoxy(x+7+40+10+40,y);cout<<char(194);
	gotoxy(x+7+40+10+40+8,y);cout<<char(194);
	gotoxy(x+7+40+10+40+8+20,y);cout<<char(194);
	for(int i=1;i<=Box_size_y;i+=2)
	{
		gotoxy(x,y+i+1);
		cout<<char(195);
		for(int j=0;j<Box_size_x;j++)
		{
			cout<<char(196);
		}
		gotoxy(x+Box_size_x+1,y+i+1);
		cout<<char(180);
	}
	for(int i=1;i<Box_size_y;i+=2)
	{
		gotoxy(x,y+i);
		cout<<char(179);
		gotoxy(x+7,y+i);
		cout<<char(179);
		gotoxy(x+7+40,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10+40,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10+40+8,y+i);
		cout<<char(179);
		gotoxy(x+7+40+10+40+8+20,y+i);
		cout<<char(179);
		gotoxy(x+Box_size_x+1,y+i);
		cout<<char(179);
	}
	gotoxy(x,y+Box_size_y);
	cout<<char(192);
	gotoxy(x+Box_size_x+1,y+Box_size_y);
	cout<<char(217);
	for(int i=2;i<Box_size_y;i+=2)
	{
		gotoxy(x+7,y+i);
		cout<<char(197);
		gotoxy(x+7+40,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10+40,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10+40+8,y+i);
		cout<<char(197);
		gotoxy(x+7+40+10+40+8+20,y+i);
		cout<<char(197);
	}
	gotoxy(x+7,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10+40,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10+40+8,y+Box_size_y);
	cout << char(193);
	gotoxy(x+7+40+10+40+8+20,y+Box_size_y);
	cout << char(193);
	SetColor(4);
	gotoxy(x+1,y+1);
	cout<< "ISBN";
	gotoxy(x+8,y+1);
	cout<<"TEN SACH";
	gotoxy(x+8+40,y+1);
	cout<<"SO TRANG";
	gotoxy(x+8+40+10,y+1);
	cout<<"TAC GIA";
	gotoxy(x+8+40+10+40,y+1);
	cout<<"NAM XB";
	gotoxy(x+8+40+10+40+8,y+1);
	cout<<"THE LOAI";
	gotoxy(x+8+40+10+40+8+20,y+1);
	cout<<"So Luot Muon";
	Normal();
}
void XoaThongTinSach()
{
	int x=90;
	int y=25;
	for(int i=0;i<10;i++)
	{
		gotoxy(x,y+i);cout<<"                                      ";
	}
}

