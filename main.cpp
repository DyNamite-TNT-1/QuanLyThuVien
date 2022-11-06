#include "XuLyDe.h"
const int dong =1;
const int cot = 2 ;
const int Up = 72;
const int Down = 80;

char thucdon[][50] =
{                   "  DOC GIA                    ",
					"  DAU SACH                   ",
					"  MUON SACH                  ",
					"  TRA SACH                   ",
					"  LAM MAT SACH               ",
					"  TIM SACH DOC GIA DANG MUON ",
					"  DANH SACH DOC GIA QUA HAN  ",
					"  TOP 10 SACH MUON NHIEU NHAT",
					"  THOAT  CHUONG TRINH        " };

int MenuDong(char td [][50],int so_item)
{
 	Normal();
  	system("cls");
	Ve_Background(); 
	Normal();  
	int chon = 0;
  	int i; 
	for ( i=0; i< so_item ; i++)
	{ 
  		gotoxy(cot, dong +i);
   		cout << td[i];
  	}
  	HighLight();
  	gotoxy(cot,dong+chon);
  	cout << td[chon];
  	char kytu;
	do 
	{
  		kytu = getch();
  		if (kytu==-32) kytu = getch();
  		switch (kytu) 
		{
    		case Up :if (chon >0)
  			  	{
  		        	Normal();
              		gotoxy(cot,dong+chon);cout << td[chon];
              		chon --;
              		HighLight();
              		gotoxy(cot,dong+chon); 	cout << td[chon];  				
  			  	}
  			  	else {
	  				Normal();
	              	gotoxy(cot,dong+chon); cout << td[chon];
	              	chon = so_item - 1;
	              	HighLight();
	              	gotoxy(cot,dong+chon); cout << td[chon];
				}
  			 	 	break;
  			case Down :if (chon+1 <so_item)
  			  	{
  		        Normal();
              	gotoxy(cot,dong+chon);	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon); 	cout << td[chon];
  				
  			  	}
  			  	else {
	  				Normal();
	              	gotoxy(cot, dong+chon); cout << td[chon];
	              	chon = 0;
	              	HighLight();
	              	gotoxy(cot, dong+chon); cout << td[chon];
				}
  			  		break;
  			case 13 : return chon+1;
  			case 27 : return -1;
  }  // end switch
  } while (1);
}
void Menu_Xuly()
{
	
	LIST_DAUSACH lDS;
	LoadFileDS(lDS);
	TREE_DG t=NULL;
	Load_DG(t);
	bool kt = true;
	while (kt==true)
	{
//		clrscr();
		int tungdo = 0;
		menu_chinh: 	
		int tt = MenuDong(thucdon, 9);
		switch (tt)
		{
			Ve_Background();
			case -1: kt=false;
					break;	
			case 1:
			{
				char Menu_DG[6][50] = { 	"  THEM DOC GIA             ",
											"  XUAT DS DOC GIA THEO MADG",
											"  XUAT DS DOC GIA THEO TEN ",
											"  XOA DOC GIA              ",
											"  HIEU CHINH DOC GIA       ",
											"  THOAT                    "};
		menu_DG:	int chon = MenuDong(Menu_DG, 6);
				if(chon==1)
				{
					nhap_DG(t);
					goto menu_DG;
				}
				else if(chon==2)
				{
					Normal();
					
					XuatDSDG_MADG(t);
					goto menu_DG;
					
				}
				else if(chon==3)
				{
					Normal();
					XuatDSDG_HOTEN(t);
					goto menu_DG;
				}
				else if(chon==4)
				{
					XoaDG(t);
					goto menu_DG;
				}
				else if (chon==5)
				{
					ChinhSuaDG(t);
					goto menu_DG;
				}
				else if(chon==6||chon==-1)
				{
					goto menu_chinh;
				}
				break;
		
			}
		case 2:
			{
			
				char Menu_DS[6][50] = {  "  THEM DAU SACH      ",
										 "  XUAT DAU SACH      ",
										 "  TIM KIEM SACH      ",
										 "  XOA SACH           ",
										 "  THEM SACH          ",
										 "  THOAT              " };
			menu_DS:	int chon = MenuDong(Menu_DS, 6);
				if (chon ==1 )
				{
					Them_DS(lDS);
					goto menu_DS;
				}
				else if (chon ==2 )
				{	
					XuatDanhSach_DS(lDS);
					goto menu_DS;
				}
				else if (chon==3)
				{
					Normal();
					TimKiemSach(lDS);
					goto menu_DS;
					
				}
				else if(chon==4)
				{
					XuLy_XoaSach(lDS);
					goto menu_DS;
				}
				else if(chon == 5)
				{
					Them_Sach(lDS);
					goto menu_DS;
				}
				else if (chon==6||chon==-1)
				{
					goto menu_chinh;
				}
				break;
			}
			case 3:
			{
					Muon_Sach(t,lDS);
					goto menu_chinh;
					break;
			}
			case 4:
			{
					TraSach	(t,lDS);
					goto menu_chinh;
					break;
			}
			case 5:
					MatSach(t,lDS);
					goto menu_chinh;
					break;
			case 6: 
					DanhSachCacSachDangMuon(t,lDS);
					goto menu_chinh;
					break;	
			case 7: 
					DS_QUAHAN(t);
					goto menu_chinh;
					break;
			case 8:
					top10sach(lDS);
					getch();
					goto menu_chinh;
					break;
			case 9: 
			{
				kt=false;
				break;
			}
			
						
		}		
	}
	GhiFileDS(lDS);
	GHI_FILE_DS_DG(t);
}
void fullscreen() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
int main()
{
	SetConsoleCP(437);
    SetConsoleOutputCP(437);
	//////////////////
	fullscreen();
	srand(time(NULL));
	//Phong_To_Ho();
	Menu_Xuly();
	return 0;
}

