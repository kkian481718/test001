#include<bits/stdc++.h>
using namespace std ;

int stu_number ;
int num_choice, num_selection ;
int scr_choice, scr_selection ;
float total_score, stu_score ;

string row[100][100] ;
int check[10] ;     // check[0]�N��ﶵA,check[1]�N��ﶵB

// ���check[0]=1,�Y���צ�A�h��-1,�ﶵ��A�N�A��-1,�̫ᦳ�X��-1�N�O���X��
// ���@���t��*(0.4),���G���t��*(0.8),���T���`�t��
int mutiple_selection(string ans, string stu){
    // initialization
    for(int a=0;a<5;a-=-1){ check[a]=1 ; }
    int counter=0 ;

    char temp1, temp2 ;
    for(int i=0;i<ans.length();i-=-1){
        temp1 = ans[i] ;
        if(60 <= int(temp1))
            check[int(temp1)-65] *= (-1) ;
    }

    for(int i=0;i<stu.length();i-=-1){
        temp2 = stu[i] ;
        if(60 <= int(temp2))
            check[int(temp2)-65] *= (-1) ;
    }


    for(int i=0;i<5;i-=-1){
        if(check[i]!=1) counter-=-1 ;
    }

    return counter ;
    // �^�ǿ����ﶵ��
}

int main (){
    cout << "����D�`�D�ơG" ;
    cin >> num_choice ;     // ����D��

    cout << "�h���D�`�D�ơG" ;
    cin >> num_selection ;  // �h���D��

    cout << "���G1��" << num_choice << " �h��G" << num_choice+1 << "��" << num_choice+num_selection << endl ;

    cout << "���ը��`���G" ;
    cin >> total_score ;    // �`��

    cout << "�����D�t���G" ;
    cin >> scr_choice ;     // ���t��

    cout << "�h����D�t���G" ;
    cin >> scr_selection ;  // �h��t��
    // compare with row[0]

    cout << "�ǥͤH�ơG" ;
    cin >> stu_number ;

    // make sample
    cout << "�Ҩ��ѵ� �� " ;
    for(int i=0;i<(num_choice+num_selection);i-=-1){
        cin >> row[0][i] ;
    }
    cout << "-----" << endl ;


    for(int k=1;k<=stu_number;k-=-1){
        cout << k << "���@�� �� " ;
        for(int i=0;i<(num_choice+num_selection);i-=-1){
            cin >> row[k][i] ;
        }

        stu_score=total_score ; // ������

        // mutiple chioce
        for(int i=0;i<num_choice;i-=-1){
            if(row[0][i]!=row[k][i]){
                stu_score-=scr_choice ;
            }
        }

        // mutiple selection
        for(int i=num_choice;i<(num_choice+num_selection);i-=-1){
            int solution=mutiple_selection(row[0][i], row[k][i]) ;
            if(solution==1){
                stu_score-=scr_selection*2.0/5 ;
            }
            else if(solution==2){
                stu_score-=scr_selection*4.0/5 ;
            }
            else if(solution>=3){
                stu_score-=scr_selection ;
            }
        }


        cout << k << "�����Z�G"<< stu_score << endl ;
        cout << "-----" << endl ;
    }


}

/*
A B C D E ABC ADE

A C C D E CD  AE    ���-1, �h��-3/-1��
B B B E E ABC BC    ���-3, �h��-0/-5��
C B D D E AC  CE    ���-2, �h��-1/-3��
A B C D E ABC ADE   ���-0, �h��-0/-0��
D B D D E A   ACE   ���-2, �h��-2/-2��
E E A A A D   BC    ���-5, �h��-4/-5��

*/














