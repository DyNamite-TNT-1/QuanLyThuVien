#include "CTDL.h"
#include "mylib.h"
string Chuan_Hoa_String(string& str);
void NhapISBN(string &kq,int &vitri,bool &ESC);
void thoi_gian_thuc(Ngay_Thang& x);
int tinh_so_ngay(Ngay_Thang n1);
//==============================================
string In_Hoa_String(string &str)
{
	for (int i=0;i<str.length();i++)
	{
		if (str[i]>=97&&str[i]<=122)
		{
			str[i]-=32;
		}
	}
	return str;
}
string Chuan_Hoa_String(string& str)
{
	//Xoa Khoang trang dau
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	// Xoa Khoang Trang Cuoi
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
	// Xoa Khoang Trang Giua
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	// Viet Hoa Chu Dau sau khoang trang
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] -= 32;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			i++;
			if (str[i] >= 97 && str[i] <= 122)
			{
				str[i] -= 32;
			}
		}
		else
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				str[i] += 32;
			}
		}
	}
	return str;
}
void NhapISBN(string &kq,int &vitri,bool &ESC)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// ISBN Chi Nhan Chu Thuong hoac Chu Hoa , va Toi Da 6 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && demKitu < MAX_ISBN)
			{
				demKitu++;
				gotoxy(x,y);
				c = toupper((char)c);
				cout<< (char)c;
				kq=kq+(char)c;
			}
			else if (c == 13)// neu la phim enter
			{
				vitri = 1;
				return;
			}
			else if (c==8 && demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key_UP
				{
					vitri = 5;
					return;
				}
				else // Neu La Cac Phim Key down, keyleft,key right
				{
					vitri = 1;
					return;
				}
			}
			
		}
	}
}
void NhapTenSach(string &kq,int &vitri,bool &ESC)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	int demSpace=0;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// Ten sach  Chi Nhan Chu Thuong hoac Chu Hoa ,so, va Toi Da 35 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
			|| (c >=  48 && c <= 57) || c == 32) && demKitu < MAX_TENSACH && demKitu >= 0)
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
			else if (c==13)// neu la phim enter
			{
				vitri = 2;
				return;
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key_UP
				{
					vitri = 0;
					return;
				}
				else // Neu La Cac Phim Key down, keyleft,key right
				{
					vitri = 2;
					return;
				}
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void NhapSoTrang(int &soTrang,int &vitri,bool &ESC)
{
	ShowCur(true);
	int temp = soTrang;
	int demKitu = 0;
	int x, y;
	while (temp != 0)
	{
		demKitu++;
		temp /= 10;
	}

	if (demKitu)
	{
		cout << soTrang;
	}
	while (true)
	{

		x = wherex() ;
		y = wherey() ;
		while (_kbhit())
		{
			int c = _getch();
			if (c >= 48 && c <= 57 && demKitu < 6)
			{
				gotoxy(x, y);
				int f = c - 48;
				cout << f;
				soTrang = soTrang * 10 + (f);
				demKitu++;
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key up
				{
					vitri = 1;
					return;
				}
				else
				{
					vitri = 3;
					return;
				}
			}
			else if (c == 13)// neu la enter
			{
				vitri = 3;
				return;
			}
			else if (c == 8 && demKitu >0)// neu la backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				soTrang /= 10;
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void NhapTacGia(string &kq,int &vitri,bool &ESC)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	int demSpace=0;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// Ten sach  Chi Nhan Chu Thuong hoac Chu Hoa ,Dau Cach, va Toi Da 35 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)  || c == 32) && demKitu < MAX_TENTG && demKitu >= 0)
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
			else if (c==13)// neu la phim enter
			{
				vitri = 4;
				return;
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key_UP
				{
					vitri = 2;
					return;
				}
				else // Neu La Cac Phim Key down, keyleft,key right
				{
					vitri = 4;
					return;
				}
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void NhapNamXB(int &NamXB,int &vitri,bool &ESC)
{
	ShowCur(true);
	int temp = NamXB;
	int demKitu = 0;
	int x, y;
	while (temp != 0)
	{
		demKitu++;
		temp /= 10;
	}

	if (demKitu)
	{
		cout << NamXB;
	}
	while (true)
	{

		x = wherex() ;
		y = wherey() ;
		while (_kbhit())
		{
			int c = _getch();
			if (c >= 48 && c <= 57 && demKitu < 4)
			{
				gotoxy(x, y);
				int f = c - 48;
				cout << f;
				NamXB = NamXB * 10 + (f);
				demKitu++;
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key up
				{
					vitri = 3;
					return;
				}
				else
				{
					vitri = 5;
					return;
				}
			}
			else if (c == 13)// neu la enter
			{
				vitri = 5;
				return;
			}
			else if (c == 8 && demKitu >0)// neu la backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				NamXB /= 10;
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void NhapTheLoai(string &kq,int &vitri,bool &ESC)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	int demSpace=0;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// Ten sach  Chi Nhan Chu Thuong hoac Chu Hoa ,so, va Toi Da 35 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)  || c == 32) && demKitu < MAX_THELOAI && demKitu >= 0)
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
			else if (c==13)// neu la phim enter
			{
				vitri = 6;
				return;
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key_UP
				{
					vitri = 4;
					return;
				}
				else // Neu La Cac Phim Key down, keyleft,key right
				{
					vitri = 0;
					return;
				}
			}
			else if(c==27)
			{
				ESC = true;
				return;
			}
			
		}
	}
}
void NhapTen(string &kq,int &vitri,bool &ESC)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// TEN CHI NHAN CHU Thuong , CHu Hoa
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)  && demKitu < MAX_TEN && demKitu >= 0))
			{
				gotoxy(x,y);
				if(c != 32)
				{
					demKitu++;
					cout << (char)c;
					kq += (char)c;
				}
			}
			else if (c==13)// neu la phim enter
			{
				vitri = 2;
				return;
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key_UP
				{
					vitri = 0;
					return;
				}
				else // Neu La Cac Phim Key down, keyleft,key right
				{
					vitri = 2;
					return;
				}
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void NhapHo(string &kq,int &vitri,bool &ESC)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	int demSpace=0;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// Ho Chi Nhan Chu Thuong hoac Chu Hoa , DAU CACH , MAX ==12
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) && demKitu < MAX_HO && demKitu >= 0)
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
			else if (c==13)// neu la phim enter
			{
				vitri = 1;
				return;
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if (c == 224)
			{
				c = _getch();
				if (c == 72)// Neu La Key_UP
				{
					vitri = 3;
					return;
				}
				else // Neu La Cac Phim Key down, keyleft,key right
				{
					vitri = 1;
					return;
				}
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void NhapPhai(int &phai, int &vitri,bool &ESC)
{
	int x;
	int y;
	x= wherex();
	y= wherey();
	phai=0;
	ShowCur(true);
	gotoxy(x,y); 
	HighLight();
	cout <<"NAM";
	gotoxy(x+10,y);
	Normal();
	cout<<"NU";
	while (true)
	{
		while(_kbhit())
		{
			int c= _getch();
				if (c==UP)
				{
					vitri=1;
					return;
				}
				else if(c==DOWN)
				{
					vitri=3;
					return;
				}
				else if(c==RIGHT&&phai==0)
				{
					phai=1;
					Normal();
					gotoxy(x,y);
					cout<<"NAM";
					HighLight();
					gotoxy(x+10,y);
					cout<<"NU";
					
				}
				else if(c==LEFT && phai==1)
				{
					phai=0;
					Normal();
					gotoxy(x+10,y);
					cout<<"NU";
					HighLight();
					gotoxy(x,y);
					cout<<"NAM";
				}
				else if(c==13)
				{
					vitri=3;
					return;
				}
				else if(c==27)
				{
				ESC=true;
				return;
				}
		}
	}
}
void NhapTrangThai(int &TrangThai,int &vitri,bool &ESC)
{
	int x;
	int y;
	x= wherex();
	y= wherey();
	TrangThai=0;
	gotoxy(x,y); 
	HighLight();
	cout <<"BI KHOA";
	gotoxy(x+20,y);
	Normal();
	cout<<"HOAT DONG";
	while (true)
	{
		while(_kbhit())
		{
			int c= _getch();
				if (c==UP)
				{
					vitri=2;
					return;
				}
				else if(c==DOWN)
				{
					vitri=0;
					return;
				}
				else if(c==RIGHT&&TrangThai==0)
				{
					TrangThai=1;
					Normal();
					gotoxy(x,y);
					cout<<"BI KHOA";
					HighLight();
					gotoxy(x+20,y);
					cout<<"HOAT DONG";
					
				}
				else if(c==LEFT && TrangThai==1)
				{
					TrangThai=0;
					Normal();
					gotoxy(x+20,y);
					cout<<"HOAT DONG";
					HighLight();
					gotoxy(x,y);
					cout<<"BI KHOA";
				}
				else if(c==13)
				{
					vitri=4;
					return;
				}
				else if(c==27)
				{
					ESC=true;
					return;
				}
		}
	}
}
int  NhapMaDocGia(int &msdg)
{
	ShowCur(true);
	
	int temp = msdg;
	int count = 0;

	while (temp != 0)
	{
		count++;
		temp /= 10;
	}

	if (count)
	{
		cout << msdg;
	}
	while (true)
	{
		while (_kbhit())
		{
			int kb_hit = _getch();
			
			if ((kb_hit >= 48 && kb_hit <= 57) 	&& ( count <= 9 && count >= 0))
			{

				int f = kb_hit - 48;
				cout << f;
				msdg = msdg * 10 + (f);
				count++;
			}
			else if (kb_hit == ENTER)
			{
				return 1;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{

				cout << "\b" << " " << "\b";
				count--;
				msdg /= 10;

			}
			else if (kb_hit == 27)
			{
				return  -1;
			}
		}
	}
}
int  NhapSoSach(int &sosach)
{
	ShowCur(true);
	int temp = sosach;
	int count = 0;

	while (temp != 0)
	{
		count++;
		temp /= 10;
	}

	if (count)
	{
		cout << sosach;
	}
	while (true)
	{
		while (_kbhit())
		{
			int kb_hit = _getch();
			
			if ((kb_hit >= 48 && kb_hit <= 57) 	&& ( count <= 9 && count >= 0))
			{

				int f = kb_hit - 48;
				cout << f;
				sosach = sosach * 10 + (f);
				count++;
			}
			else if (kb_hit == ENTER)
			{
				return 1;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				sosach /= 10;
			}
			else if (kb_hit == 27)
			{
				return  -1;
			}
		}
	}
}
void NhapViTri(string &kq, bool &ESC,bool &luu)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	int demSpace=0;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach, dau phay, va so.
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57 )
				|| c == 32 || c == 44) && demKitu < MAX_VITRI && demKitu >= 0)
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
			else if (c==13)// neu la phim enter
			{
				luu=true;
				return;
			}
			else if (c==8&&demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
			}
			
		}
	}
void NhapMaSach(string &kq,bool &ESC,bool &luu)
{
	Normal();
	ShowCur(true);
	cout << kq;
	int demKitu= (int)kq.length();
	int x,y;
	while(true)
	{
		x=wherex();
		y=wherey();
		while (_kbhit())
		{
			int c = _getch();
			// ISBN Chi Nhan Chu Thuong hoac Chu Hoa ,So va Toi Da 8 ky tu
			if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)||(c>=48&&c<=57))&& demKitu <= 8)
			{
				demKitu++;
				gotoxy(x,y);
				c = toupper((char)c);
				cout<< (char)c;
				kq=kq+(char)c;
			}
			else if (c == 13)// neu la phim enter
			{
				luu=true;
				return;
			}
			else if (c==8 && demKitu>0) // Neu La Phim backspace
			{
				cout << "\b" << " " << "\b";
				demKitu--;
				kq.erase(kq.length() - 1, 1);
			}
			else if(c==27)
			{
				ESC=true;
				return;
			}
		}
	}
}
void thoi_gian_thuc(Ngay_Thang& x)
{
	time_t t = time(NULL);
	tm* now = localtime(&t);
	x.ngay = now->tm_mday;
	x.thang = now->tm_mon + 1;
	x.nam = now->tm_year + 1900;
}
int tinhNgay(Ngay_Thang dt)
{
	if (dt.thang < 3) {
		dt.nam--;
		dt.thang += 12;
	}
	return 365 * dt.nam + dt.nam / 4 - dt.nam / 10 + dt.nam / 400 + (153 * dt.thang - 457) / 5 + dt.ngay - 306;
}
int KhoangCachNgay(Ngay_Thang nt1)
{
	Ngay_Thang nt2;
	thoi_gian_thuc(nt2);
	return (tinhNgay(nt2) - tinhNgay(nt1));
}

