
// YYX_TEST2_1View.cpp : CYYX_TEST2_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "YYX_TEST2_1.h"
#endif

#include "YYX_TEST2_1Doc.h"
#include "YYX_TEST2_1View.h"
#include <fstream>
#include<sstream>
#include <iostream>
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYYX_TEST2_1View

IMPLEMENT_DYNCREATE(CYYX_TEST2_1View, CFormView)

BEGIN_MESSAGE_MAP(CYYX_TEST2_1View, CFormView)
	ON_BN_CLICKED(IDC_ADD, &CYYX_TEST2_1View::OnBnClickedAdd)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CYYX_TEST2_1View::OnTvnSelchangedTree1)
	ON_COMMAND(ID_32771, &CYYX_TEST2_1View::OnAdd)
	ON_BN_CLICKED(IDC_FIX, &CYYX_TEST2_1View::OnBnClickedFix)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CYYX_TEST2_1View::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_DELETE, &CYYX_TEST2_1View::OnBnClickedDelete)
	ON_COMMAND(ID_32772, &CYYX_TEST2_1View::OnSearch)
END_MESSAGE_MAP()

// CYYX_TEST2_1View 构造/析构

CYYX_TEST2_1View::CYYX_TEST2_1View()
	: CFormView(CYYX_TEST2_1View::IDD)
{
	// TODO: 在此处添加构造代码
	sum=0;
	is_select=0;

}

CYYX_TEST2_1View::~CYYX_TEST2_1View()
{
}

void CYYX_TEST2_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, C_Tree);
	DDX_Control(pDX, IDC_LIST1, M_List);
}

BOOL CYYX_TEST2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CFormView::PreCreateWindow(cs);
}

void CYYX_TEST2_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//树的初始化
	InitTree();



	//列表的初始化
	CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    M_List.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    M_List.SetExtendedStyle(M_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加六列
	M_List.InsertColumn(0, _T("爱好"), LVCFMT_CENTER, rect.Width()/7, 0); 
	M_List.InsertColumn(0, _T("入会时间"), LVCFMT_CENTER, rect.Width()/7, 1); 
	M_List.InsertColumn(0, _T("身份证号"), LVCFMT_CENTER, rect.Width()/7, 2); 
	M_List.InsertColumn(0, _T("会员等级"), LVCFMT_CENTER, rect.Width()/7, 3); 
	M_List.InsertColumn(0, _T("性别"), LVCFMT_CENTER, rect.Width()/7, 4); 
	M_List.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width()/7, 5); 
	M_List.InsertColumn(0, _T("会员号"), LVCFMT_CENTER, rect.Width()/7, 6); 
	
}


// CYYX_TEST2_1View 诊断

#ifdef _DEBUG
void CYYX_TEST2_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CYYX_TEST2_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CYYX_TEST2_1Doc* CYYX_TEST2_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYYX_TEST2_1Doc)));
	return (CYYX_TEST2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CYYX_TEST2_1View 消息处理程序


void CYYX_TEST2_1View::OnBnClickedAdd()
{
	add.DoModal();
	M_List.DeleteAllItems();
	sum=0;//清掉所有行
	ReadFile();//重新绘制列表
	// TODO: 在此添加控件通知处理程序代码
}


void CYYX_TEST2_1View::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	
	fstream  f("member.txt");//创建一个fstream文件流对象
    string  line; //读取每一行
	string  data="";
	string::size_type idx;
	char flag=' ';
	int cont=0;
	sum=0;

	HTREEITEM node=C_Tree.GetSelectedItem();
	CString get=C_Tree.GetItemText(node);
	if(get==_T("全部会员"))
	{
		M_List.DeleteAllItems();//清掉所有行
		ReadFile();
	}
	else if(get==_T("高级会员"))
	{
		M_List.DeleteAllItems();//清掉所有行
		while(getline(f,line))//会自动把\n换行符去掉 
		{
			idx=line.find("高级会员");
			if(idx!=string::npos)
			{
				stringstream ss(line);
				string tok;
				while(getline(ss,tok,flag))
				{
					if(cont==0) C_Number=tok.c_str();
					else if (cont==1) C_Name=tok.c_str();
					else if (cont==2) C_IDNumber=tok.c_str();
					else if (cont==3) C_Sex=tok.c_str();
					else if (cont==4) C_Grade=tok.c_str();
					else if (cont==5) C_Time=tok.c_str();
					else{
						C_Hobby=tok.c_str();
						cont=-1;
						InitList(sum);
						sum++;
					}
					cont++;
				}	
			}
		}
	}
	else if(get==_T("中级会员"))
	{
		M_List.DeleteAllItems();
		while(getline(f,line))//会自动把\n换行符去掉 
		{
			idx=line.find("中级会员");
			if(idx!=string::npos)
			{
				stringstream ss(line);
				string tok;
				while(getline(ss,tok,flag))
				{
					if(cont==0) C_Number=tok.c_str();
					else if (cont==1) C_Name=tok.c_str();
					else if (cont==2) C_IDNumber=tok.c_str();
					else if (cont==3) C_Sex=tok.c_str();
					else if (cont==4) C_Grade=tok.c_str();
					else if (cont==5) C_Time=tok.c_str();
					else{
						C_Hobby=tok.c_str();
						cont=-1;
						InitList(sum);
						sum++;
					}
					cont++;
				}	
			}
		}
	}
	else if(get==_T("低级会员")){
		M_List.DeleteAllItems();
		while(getline(f,line))//会自动把\n换行符去掉 
		{
			idx=line.find("低级会员");
			if(idx!=string::npos)
			{
				stringstream ss(line);
				string tok;
				while(getline(ss,tok,flag))
				{
					if(cont==0) C_Number=tok.c_str();
					else if (cont==1) C_Name=tok.c_str();
					else if (cont==2) C_IDNumber=tok.c_str();
					else if (cont==3) C_Sex=tok.c_str();
					else if (cont==4) C_Grade=tok.c_str();
					else if (cont==5) C_Time=tok.c_str();
					else{
						C_Hobby=tok.c_str();
						cont=-1;
						InitList(sum);
						sum++;
					}
					cont++;
				}	
			}
		}
	}
	f.close();
}




void CYYX_TEST2_1View::InitTree(void)
{
	C_Tree.ModifyStyle(0,TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);
	Member=C_Tree.InsertItem(_T("全部会员"));
	SeniorMember=C_Tree.InsertItem(_T("高级会员"));
	IntermediateMember=C_Tree.InsertItem(TEXT("中级会员"));
	JuniorMember=C_Tree.InsertItem(TEXT("低级会员"));
}




void CYYX_TEST2_1View::InitList(int sum)
{
	// 在列表视图控件中插入列表项，并设置列表子项文本 
	
	M_List.InsertItem(sum, C_Number);   
    M_List.SetItemText(sum, 1, C_Name);   
    M_List.SetItemText(sum, 2, C_Sex);
	M_List.SetItemText(sum, 3, C_Grade);
	M_List.SetItemText(sum, 4, C_IDNumber);
	M_List.SetItemText(sum, 5, C_Time);
	M_List.SetItemText(sum, 6, C_Hobby);
}


void CYYX_TEST2_1View::OnAdd()
{
	add.DoModal();
	M_List.DeleteAllItems();
	sum=0;//清掉所有行
	ReadFile();//重新绘制列表
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST2_1View::OnBnClickedFix()
{
	fix.DoModal();
	M_List.DeleteAllItems();
	sum=0;//清掉所有行
	ReadFile();//重新绘制列表
	// TODO: 在此添加控件通知处理程序代码
}


void CYYX_TEST2_1View::ReadFile(void)
{
	char flag=' ';
	fstream  f("member.txt");//创建一个fstream文件流对象
    string  line; //读取每一行
	int cont=0;
	while(getline(f,line))//会自动把\n换行符去掉 
    {
		stringstream ss(line);
		string tok;
		while(getline(ss,tok,flag))
		{
			if(cont==0) C_Number=tok.c_str();
			else if (cont==1) C_Name=tok.c_str();
			else if (cont==2) C_IDNumber=tok.c_str();
			else if (cont==3) C_Sex=tok.c_str();
			else if (cont==4) C_Grade=tok.c_str();
			else if (cont==5) C_Time=tok.c_str();
			else{
				C_Hobby=tok.c_str();
				cont=-1;
				InitList(sum);
				sum++;
			}
			cont++;
		}
	}
	f.close();
}


void CYYX_TEST2_1View::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	is_select=1;
	int Cur=M_List.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	//m_ListGroup 是CList，获得的是列表中选中的第几行
	if (Cur<0)//如果是0行，退出
		return;
	C_Number=M_List.GetItemText(Cur,0);//获得Cur行第1列的内容
	C_Name=M_List.GetItemText(Cur,1);
	C_Sex=M_List.GetItemText(Cur,2);
	C_Grade=M_List.GetItemText(Cur,3);
	C_IDNumber=M_List.GetItemText(Cur,4);
	C_Time=M_List.GetItemText(Cur,5);
	C_Hobby=M_List.GetItemText(Cur,6);
	Show();
}

//展示在界面上
void CYYX_TEST2_1View::Show(void)
{
	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(C_Number);
	((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(C_Name);
	((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(C_IDNumber);
	((CEdit *)GetDlgItem(IDC_COMBO2))->SetWindowText(C_Sex);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->SetWindowText(C_Time);
	((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(C_Hobby);
}

//删除选中的
void CYYX_TEST2_1View::OnBnClickedDelete()
{
	if(is_select==1){
		int flag=0;
		string mC_Number=CT2A(C_Number.GetString());
		string mC_Name=CT2A(C_Name.GetString());
		string mC_IDNumber=CT2A(C_IDNumber.GetString());
		string mC_Sex=CT2A(C_Sex.GetString());
		string mC_Grade=CT2A(C_Grade.GetString());
		string mC_Time=CT2A(C_Time.GetString());
		string mC_Hobby=CT2A(C_Hobby.GetString());

		fstream  f("member.txt");//创建一个fstream文件流对象
		string  line; //读取每一行
		string data="";
		string::size_type idx;
	
		while(getline(f,line))//会自动把\n换行符去掉 
		{
			string ber=line.substr(0,4);
			idx=ber.find(mC_Number);
			if(idx==string::npos)
			{
				data+=line;
				data+='\n';
			}
			else
			{
				flag=1;
				MessageBox(_T("删除成功"));
			}
		}
		if (flag)
		{
			f.close();
			//写入文件
			ofstream out;
			out.open("member.txt");
			out.flush();
			out<<data;
			out.close();
			M_List.DeleteAllItems();//清掉所有行
			sum=0;
			ReadFile();//重新绘制列表
		}
		else{
			f.close();
			MessageBox(_T("请先选中一个会员"));
		}
	}
	else{
		MessageBox(_T("请先选中一个会员"));
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CYYX_TEST2_1View::OnSearch()
{
	int mark=0;
	int cont=0;//计算文件行数，防止越界
	search.DoModal();
	fstream  f("member.txt");//创建一个fstream文件流对象
    string  line; //读取每一行
	while(getline(f,line)) cont++;
	while(1)
	{
		if(mark>cont){
			mark=0;
			break;
		}
		C_Number=M_List.GetItemText(mark,0);
		C_Name=M_List.GetItemText(mark,1);
		C_Sex=M_List.GetItemText(mark,2);
		C_Grade=M_List.GetItemText(mark,3);
		C_IDNumber=M_List.GetItemText(mark,4);
		C_Time=M_List.GetItemText(mark,5);
		C_Hobby=M_List.GetItemText(mark,6);
		if(C_Number==search.C_Number)
		{
			Show();
			M_List.DeleteAllItems();//清空所有行
			sum=0;
			InitList(sum);
			mark++;
			break;
		}
		mark++;
	}
	if(mark==0) MessageBox(_T("没找到"));
	// TODO: 在此添加命令处理程序代码
}
