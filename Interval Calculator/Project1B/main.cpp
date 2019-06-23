//
//  main.cpp
//  Game1
//
//  Created by Mervin Li on 2018-09-28.
//  Copyright © 2018 Mervin Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
int interval_calculator();
bool int_check(double a, double b);
int main ();

int main()
{
    interval_calculator();
    return 0;
}

int interval_calculator()
{
    double imed[2]{0,0};
    double mem[2]{0,0};
    bool init{false};
    bool init2{false};
    std::string str{0};
    double a{0};
    double b{0};
    double c{0};
    double d{0};
    while (str!="exit")
    {
        std::cout<<"input :> ";
        std::cin>>str;
        if (str=="exit")
        {
            std::cout<<"Bye bye: Terminating interval calculator program.";
        }
        
        if (str=="enter")
        {
            
            std::cin>>a;
            std::cin>>b;
            if (a>b)
            {
                std::cout<<"Error: invalid interval as "<<a<<" > "<<b<<std::endl;
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                imed[0]=a;
                imed[1]=b;
                init=true;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="negate")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                double temp{0};
                temp=imed[0]*(-1);
                imed[0]=imed[1]*(-1);
                imed[1]=temp;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                
            }
        }
        if (str=="invert")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if( imed[0]<=0 && imed[1]>=0)
            {
                std::cout<<"Error: division by zero"<<std::endl;
                imed[0]=0;
                imed[1]=0;
                init=false;
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                imed[0]=1/imed[0];
                imed[1]=1/imed[1];
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="ms")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                
                mem[0]=imed[0];
                mem[1]=imed[1];
                init2=true;
                std::cout<<"["<<mem[0]<<", "<<mem[1]<<"]"<<std::endl;
            }
        }
        if (str=="mr")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if (init2==false)
            {
                
            }
            else
            {
                imed[0]=mem[0];
                imed[1]=mem[1];
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="mc")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                
                mem[0]=0;
                mem[1]=0;
                init2=false;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }

        
        if (str=="m+")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                
                mem[0]+=imed[0];
                mem[1]+=imed[1];
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        
        if (str=="m-")
        {
            if ((init==false) || (init2==false))
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                
                mem[0]-=imed[0];
                mem[1]-=imed[1];
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        
        if (str=="scalar_add")
        {
            std::cin>>c;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                imed[0]+=c;
                imed[1]+=c;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="scalar_subtract")
        {
            std::cin>>c;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                imed[0]-=c;
                imed[1]-=c;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="scalar_multiply")
        {
            std::cin>>c;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                imed[0]*=c;
                imed[1]*=c;
                if (c<0)
                {
                    double temp{0};
                    temp=imed[1];
                    imed[1]=imed[0];
                    imed[0]=temp;
                }
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="scalar_divide")
        {
            std::cin>>c;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if (c==0)
            {
                std::cout<<"Error: division by zero"<<std::endl;
                imed[0]=0;
                imed[1]=0;
                init=false;
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                imed[0]/=c;
                imed[1]/=c;
                if (c<0)
                {
                    double temp{0};
                    temp=imed[1];
                    imed[1]=imed[0];
                    imed[0]=temp;
                }
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="scalar_divide_by")
        {
            std::cin>>c;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if( imed[0]<=0 && imed[1]>=0)
            {
                std::cout<<"Error: division by zero"<<std::endl;
                imed[0]=0;
                imed[1]=0;
                init=false;
                std::cout<<"- -"<<std::endl;
            }
            
            else
            {                                     //different in notes then what it says followed to make it like sample
                if(c>=0)
                {
                    imed[0]=c/imed[0];
                    imed[1]=c/imed[1];
                    double temp{0};
                    temp=imed[1];
                    imed[1]=imed[0];
                    imed[0]=temp;
                }
                else
                {
                    imed[0]=c/imed[0];
                    imed[1]=c/imed[1];
                }
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        
        if (str=="interval_add")
        {
            std::cin>>c;
            std::cin>>d;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if (c>d)
            {
                std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (init==false)
                {
                    std::cout<<"- -"<<std::endl;
                }
                else
                {
                    std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                }
            }
            else
            {
                imed[0]+=c;
                imed[1]+=d;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="interval_subtract")
        {
            std::cin>>c;
            std::cin>>d;
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if (c>d)
            {
                std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (init==false)
                {
                    std::cout<<"- -"<<std::endl;
                }
                else
                {
                    std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                }
            }
            else
            {
                imed[0]-=d;
                imed[1]-=c;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="interval_multiply")
        {
            std::cin>>c;
            std::cin>>d;
            if (c>d)
            {
                std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (init==false)
                {
                    std::cout<<"- -"<<std::endl;
                }
                else
                {
                    std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                }
            }
            
            else if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                double ac=imed[0]*c;
                double ad=imed[0]*d;
                double bc=imed[1]*c;
                double bd=imed[1]*d;
                double max=ac,min=ac;
                if(ad>max)
                {
                    max=ad;
                }
                else if(ad<min)
                {
                    min=ad;
                }
                if(bc>max)
                {
                    max=bc;
                }
                else if(bc<min)
                {
                    min=bc;
                }
                if(bd>max)
                {
                    max=bd;
                }
                else if(bd<min)
                {
                    min=bd;
                }
                imed[0]=min;
                imed[1]=max;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="interval_divide")            //maybe gotta say invalid first
        {
            std::cin>>c;
            std::cin>>d;
            if (c>d)
            {
                std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (init==false)
                {
                    std::cout<<"- -"<<std::endl;
                }
                else
                {
                    std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                }
            }
            
            else if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else if( c<=0 && d>=0)
            {
                std::cout<<"Error: division by zero"<<std::endl;
                imed[0]=0;
                imed[1]=0;
                init=false;
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                double ac=imed[0]/c;
                double ad=imed[0]/d;
                double bc=imed[1]/c;
                double bd=imed[1]/d;
                double max=ac;
                double min=ac;
                if(ad>max)
                {
                    max=ad;
                }
                else if(ad<min)
                {
                    min=ad;
                }
                if(bc>max)
                {
                    max=bc;
                }
                else if(bc<min)
                {
                    min=bc;
                }
                if(bd>max)
                {
                    max=bd;
                }
                else if(bd<min)
                {
                    min=bd;
                }
                imed[0]=min;
                imed[1]=max;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
        if (str=="intersect")
        {
            std::cin>>c;
            std::cin>>d;
            if (c>d)
            {
                std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (init==false)
                {
                    std::cout<<"- -"<<std::endl;
                }
                else
                {
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                }
            }
            
            else if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                if (c>imed[0]&&c<imed[1])
                {
                    imed[0]=c;
                }
                if(imed[1]>d)
                {
                    imed[1]=d;
                }
                if (c>imed[1])
                {
                    imed[0]=0;
                    imed[1]=0;
                    init=false;
                    std::cout<<"- -"<<std::endl;
                }
                else
                {
                    std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                }
            }
        }
        
        if (str=="integers")
        {
            if (init==false)
            {
                std::cout<<"- -"<<std::endl;
            }
            else
            {
                int a{0};
                int b{0};
                a=std::ceil(imed[0]);
                b=std::floor(imed[1]);
                int k{a};
                std::cout<<k;
                k++;
                while (k<=b)
                {
                    std::cout<<", "<<k;
                    k++;
                }
                std::cout<<std::endl;
                std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
            }
        }
         if (str=="cartesian_integers")
         {
             std::cin>>c;
             std::cin>>d;
             if (c>d)
             {
                 std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                 if (init==false)
                 {
                     std::cout<<"- -"<<std::endl;
                 }
                 else
                 {
                     std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
                 }
             }
             
             else if (init==false)
             {
                 std::cout<<"- -"<<std::endl;
             }
             else
             {
                 int a1=round(imed[0]);
                 int b1=floor(imed[1]);
                 int c1=round(c);
                 int d1=round(d);
                 std::cout<<"("<<a1<<","<<c1<<"), "<<"("<<a1<<","<<d1<<"), "<<"("<<b1<<","<<c1<<"), "<<"("<<b1<<","<<d1<<")"<<std::endl;
                 std::cout<<"["<<imed[0]<<", "<<imed[1]<<"]"<<std::endl;
             }
         }
        
    }
    return 0;
    
}
