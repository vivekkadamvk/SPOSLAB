#include<bits/stdc++.h>
#include<vector>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
int lc,sa,l,opcode,len,k=0,lc_count=0,s_index=1,i=0;
char mo[20],op1[20],op2[20],d[20],tt[20],c1,c2;

vector<string> lit;

int x=1;
vector<int>alpha(27);
for(int i=0;i<27;i++) alpha[i]=i;

    fstream i_file("input.txt");
    fstream d_file("data.txt");
    fstream p_file("phase1.txt");
    fstream s_file("symtab.txt");
    fstream l_file("literaltab.txt");
    fstream po_file("pool.txt");

    string ip_line,data_line;
    while (getline(i_file, ip_line)) 
    {
        mo[0] = '\0';
        op1[0] = '\0';
        op2[0] = '\0';

        sscanf(ip_line.c_str(), "%s %s %s", mo, op1, op2);
        cout<<mo<<" "<<op1<<" "<<op2<<endl;
    if(strcmp(mo,"START")==0)
    {
        lc = stoi(op1);
        p_file<<" "<<"("<<"AD"<<","<<"01"<<")";
        p_file<<"("<<"C"<<","<<lc<<")"<<endl;
    }
    else
        {
    while (getline(d_file, data_line))
    {
            sscanf(data_line.c_str(), "%d %s %s", &opcode, d, tt);
                if(strcmp(mo,d)==0)
                {
                    p_file<<lc<<"("<<tt<<","<<opcode<<")";
                    lc++;
                        while (getline(d_file, data_line))
                        {
                            sscanf(data_line.c_str(), "%d %s %s", &opcode, d, tt);
                            if(strcmp(op1,d)==0)
                            {
                                p_file<<"("<<tt<<","<<opcode<<")";
                                    while (getline(d_file, data_line))
                                    {
                                        sscanf(data_line.c_str(), "%d %s %s", &opcode, d, tt);
                                        if(strcmp(op2,d)==0)
                                        {
                                            p_file<<"("<<tt<<","<<opcode<<")";
                                            break;
                                        }
                                        else if(strlen(op2)==1)
                                        {
                                            int ch = (int)op1[0] - 'A';
                                            p_file<<"("<<"S"<<","<<ch+1<<")";

                                            break;
                                        }
                                        else if( op2[0] =='=')
                                        {
                                            lit.push_back(op2);
                                            p_file<<"("<<"L"<<","<<lc_count<<")";        
                                            break;
                                        }
                                    }   
                            }
                            else if(strlen(op1)==1)
                            {
                                int ch = (int)op1[0] - 'A';
                                p_file<<"("<<"S"<<","<<ch+1<<")";
                                break;
                            }
                        }
                }
                else if(strlen(mo)==1)
                {
                    k = stoi(op2);
                    
                    while (getline(d_file, data_line))
                        {
                            sscanf(data_line.c_str(), "%d %s %s", &opcode, d, tt);
                                if(strcmp(op1,d)==0)
                                {
                                    p_file<<lc<<"("<<tt<<","<<opcode<<")";

                                    s_file<<s_index<<"  "<<mo<<"  "<<lc<<endl;
                                    s_index++;

                                    lc = lc + k;
                                    if(isdigit(op2[0])==0)
                                    {
                                        p_file<<"("<<"C"<<","<<k<<")"<<endl;
                                    }
                                }
                        }

                    break;
                }
                else if(strcmp(mo,"LTORG")==0)
                {
                    if(lit.size()!=0)
                    {
                    po_file<<lc_count+1;
                    for(int i=0 ; i<lit.size() ;i++)
                        {   
                            lc_count++; 
                            l_file<<lc_count<<"  "<<lit[i]<<"  "<<lc<<endl;
                            p_file<<lc<<"("<<"DL"<<","<<"02"<<")"<<"("<<"C"<<","<<lit[i][2]<<")";
                            lc++;
                        }
                        lit.clear();
                    }
                    break;
                }     
                else if(strcmp(mo,"END")==0)
                {
                    if(lit.size()!=0)
                    {
                    for(int i=0 ; i<lit.size() ;i++)
                        {   
                            lc_count++;     
                            l_file<<lc_count<<"  "<<lit[i]<<"  "<<lc<<endl;
                            lc++;
                        }
                        lit.clear();
                    }
                    p_file<<"("<<"AD"<<","<<"02"<<")"<<"("<<"L"<<","<<lc_count<<")";
                    break;
                }      
            }
            p_file<<endl;
            d_file.clear();
            d_file.seekg(0, ios::beg);
        }

    }
}
