//
//  main.cpp
//  project 2
//
//  Created by Mervin Li on 2018-11-12.
//  Copyright © 2018 Mervin Li. All rights reserved.
//

#include <iostream>
#include "Polynomial.h"


#ifndef MARMOSET_TESTING
int main()
{
    poly_t poly1{nullptr, 0};
    poly_t poly2{nullptr, 0};
    poly_t poly3{nullptr, 0};
    double co1[1]{1};
    double co3[12]{64.4622496013, 0.0280366249915, 12.759753383, 99.9981366677, 43.0055462399, 70.6769615215, 23.42, 324.5, 1.2, 31.4, 41.4, 5.1};
    double co2[5]{24, 10, -15, 0, 1};
    init_poly(poly3, co3, 11);
    init_poly(poly1, co1, 0);
    init_poly(poly2, co2, 4);
    poly_multiply(poly2, poly2);
    try {
        poly_degree(poly1);
    } catch (...) {
        std::cout<<"its a null";
    }
    return 0;
}
#endif
void init_poly( poly_t &p, double const init_coeffs[], unsigned int const init_degree )
{
    if (p.a_coeffs!=nullptr)
    {
        delete[] p.a_coeffs;
        p.a_coeffs=nullptr;
    }
    p.a_coeffs=new double[init_degree+1];
    for (std::size_t index{0}; index<=init_degree; index++)
    {
        p.a_coeffs[index]=init_coeffs[index];
        std::cout<<p.a_coeffs[index]<<std::endl;
        std::cout<<&(p.a_coeffs[index])<<std::endl;
    }
    p.degree=init_degree;
}

void destroy_poly(poly_t &p)
{
    delete[] p.a_coeffs;
    p.a_coeffs=nullptr;
    p.degree=0;
}

unsigned int poly_degree(poly_t const &p)
{
    if (p.a_coeffs==nullptr)
    {
        throw 0;
    }
    else
    {
        return p.degree;
    }
}

double poly_coeff(poly_t const &p, unsigned int n)
{
    if (p.a_coeffs==nullptr)
    {
        throw 0;
    }
    else if (p.degree<n)
    {
        return 0;
    }
    else
    {
        double temp{0};
        double *temp1{nullptr};
        temp1=p.a_coeffs+n;
        temp=*temp1;
        temp1=nullptr;
        return temp;
    }
}

double poly_val (poly_t const &p, double const x)
{
    if (p.a_coeffs==nullptr)
    {
        throw 0;
    }
    else
    {
    double result = p.a_coeffs[p.degree];
    for(int i=p.degree-1; i >= 0 ; --i)
        result = result * x + p.a_coeffs[i];
    return result;
    }
}

void poly_add(poly_t &p, poly_t const &q)
{
    if (p.a_coeffs==nullptr || q.a_coeffs==nullptr)
    {
        throw 0;
    }
    else
    {
        int new_capacity{0};
        if (q.degree>p.degree)
        {
            new_capacity=q.degree;
        }
        else
        {
            new_capacity=p.degree;
        }
        double *p_new{new double[new_capacity+1]};           //p greater degree works
        for (std::size_t index{0}; index<=new_capacity; index++)
        {
            if (p.degree>q.degree)
            {
                if (index<=q.degree)
                {
                    p_new[index]=p.a_coeffs[index]+q.a_coeffs[index];
                }
                else
                {
                    p_new[index]=p.a_coeffs[index];
                }
            }
            else
            {
                if (index<=p.degree)
                {
                    p_new[index]=p.a_coeffs[index]+q.a_coeffs[index];
                }
                else
                {
                    p_new[index]=q.a_coeffs[index];
                }
            }
        }
        while (p_new[new_capacity]==0)
        {
            new_capacity--;
        }
        if (new_capacity<0)
        {
            new_capacity=0;
        }
        delete[] p.a_coeffs;
        p.a_coeffs=p_new;
        p.degree=new_capacity;
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            std::cout<<p.a_coeffs[index]<<std::endl;
        }
    }
    
}

void poly_subtract(poly_t &p, poly_t const &q)
{
    if (p.a_coeffs==nullptr || q.a_coeffs==nullptr)
    {
        throw 0;
    }
    else
    {
        int new_capacity{0};
        if (q.degree>p.degree)
        {
            new_capacity=q.degree;
        }
        else
        {
            new_capacity=p.degree;
        }
        double *p_new{new double[new_capacity+1]};
        for (std::size_t index{0}; index<=new_capacity; index++)
        {
            if (p.degree>q.degree)
            {
                if (index<=q.degree)
                {
                    p_new[index]=p.a_coeffs[index]-q.a_coeffs[index];
                }
                else
                {
                    p_new[index]=p.a_coeffs[index];
                }
            }
            else
            {
                if (index<=p.degree)
                {
                    p_new[index]=p.a_coeffs[index]-q.a_coeffs[index];
                }
                else
                {
                    p_new[index]=-1*q.a_coeffs[index];
                }
            }
        }
        while (p_new[new_capacity]==0)
        {
            new_capacity--;
        }
        if (new_capacity<0)
        {
            new_capacity=0;
        }
        delete[] p.a_coeffs;
        p.a_coeffs=p_new;
        p.degree=new_capacity;
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            std::cout<<p.a_coeffs[index]<<std::endl;
        }
    }
    
}

void poly_multiply(poly_t &p, poly_t const &q)
{
    if (p.a_coeffs==nullptr || q.a_coeffs==nullptr) // max degree is degree of max added together so capacity is +1 of that..
    {
        throw 0;
    }
    else
    {
        int new_deg{0};
        new_deg=p.degree+q.degree;
        int total{0};
        total=(p.degree+1)*(q.degree+1);
        double *ptot{new double[total]};
        for (std::size_t index{0}; index<total; index++)
        {
            ptot[index]=0;
        }
        for (std::size_t index{0}; index<=p.degree; index++)  // dont need total??
        {
            for (std::size_t index2{0}; index2<=q.degree; index2++)
            {
                ptot[index+index2]=ptot[index+index2]+( p.a_coeffs[index]*q.a_coeffs[index2]);
            }
        }
        double *p_new{new double[new_deg+1]};
        for (std::size_t index{0}; index<=new_deg; index++)
        {
            p_new[index]=ptot[index];
        }
        delete[] p.a_coeffs;
        p.a_coeffs=p_new;
        p.degree=new_deg;
        delete[]ptot;
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            std::cout<<p.a_coeffs[index]<<std::endl;
        }
    }
}


double poly_divide( poly_t &p, double r )
{
    if (p.a_coeffs==nullptr) // max degree is degree of max added together so capacity is +1 of that..
    {
        throw 0;
    }
    else if (p.degree==0)
    {
        double temp{0};
        temp=p.a_coeffs[0];
        p.a_coeffs[0]=0;
        return temp;
    }
    else
    {
        double *pdiv{new double[p.degree+1]};
        double *rev{new double[p.degree+1]};
        double *n1{new double[p.degree]};
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            rev[index]=p.a_coeffs[p.degree-index];
  //          std::cout<<rev[index]<<std::endl;
        }
        pdiv[0]=rev[0];
        int temp{0};
        for (std::size_t index{1}; index<=p.degree; index++)
        {
            pdiv[index]=rev[index]+(pdiv[temp]*r);
            temp++;
  //          std::cout<<pdiv[index]<<std::endl;
        }
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            rev[index]=pdiv[p.degree-index];
  //          std::cout<<rev[index]<<std::endl;
        }
        int dege{0};
        for (std::size_t index{0}; index<p.degree; index++)
        {
            n1[index]=rev[index+1];
 //           std::cout<<p.a_coeffs[index]<<std::endl;
            dege++;
        }
        double temp2{rev[0]};
        delete[] rev;
        delete[] p.a_coeffs;
        p.a_coeffs=n1;
        rev=nullptr;
        delete[] pdiv;
        pdiv=nullptr;
        p.degree=dege-1;
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            std::cout<<p.a_coeffs[index]<<std::endl;
        }
        return temp2;
    }
    

}
void poly_diff( poly_t &p )
{
    if (p.a_coeffs==nullptr) // max degree is degree of max added together so capacity is +1 of that..
    {
        throw 0;
    }
    else if (p.degree==0)
    {
        double *p_new{new double[1]};
        p_new[0]=0;
        delete[] p.a_coeffs;
        p.a_coeffs=p_new;
    }
    else
    {
        int deg{1};
        double *p_new{new double[p.degree]};
        for (std::size_t index{0}; index<p.degree; index++)
        {
            p_new[index]=p.a_coeffs[deg]*deg;
            std::cout<<p_new[index]<<std::endl;
            deg++;
        }
        delete[] p.a_coeffs;
        p.a_coeffs=p_new;
        p.degree=deg-2;
        for (std::size_t index{0}; index<=p.degree; index++)
        {
            std::cout<<p.a_coeffs[index]<<std::endl;
        }
    }
}
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n )
{
    if (p.a_coeffs==nullptr)
    {
        throw 0;
    }
    else
    {
        double h{0};
        h=(b-a)/n;
        double value{0};
        value=poly_val(p, b) + poly_val(p, a);
        double x{0};
        for (int index{1}; index<n; index++)
        {
            x=a+index*h;
            value += 2*poly_val(p, x);
        }
        value=(h/2)*value;
        return value;
        
        
    }
    
}
