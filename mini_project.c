#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//S refers to distance
//U refers to initial speed
//V refers to speed at any given moment, value is 0 at max height
//z refers to angle from horizontal (in radians)
//zdeg refers to angle in degrees
//t refers to time
//A refers to acceleration

int main(){

    int a,B,E,*p; float z,S,Sx,Sy,V,Vx,Vy,A,U,Ux,Uy,t,Sxx,Syy,zdeg; //definition of variables required (t=time, z=angle to horizontal)
    const float g=9.81;


        for(a=0;a<5;a++)
        {
            switch(a){

            case 0:
            U=110; B=0;
            break;

            case 1:
            U=115; B=1;
            break;

            case 2:
            U=120; B=2;
            break;

            case 3:
            U=125; B=3;
            break;

            case 4:
            U=130; B=4;
            break;
        }
            z=45;
            Ux=U*cos(z);
            Uy=U*sin(z);
            Vx=Ux;
            t=Uy/g;
            Vy=Uy-g*t;
            Sx=Ux*t;
            Sy=Uy*t-0.5*g*t*t;


            printf("Augmentation number: %d\t",a);
            printf("Boosting charge: %d\t", B);
            printf("Muzzle Velocity: %.2f\n", U);
            printf("Maximum range: %.2f\t", Sx);
            printf("Maximum height: %.2f\t", Sy);
            printf("Launch Angle: %.2f\n\n",z);

        }

        //p=&z; //pointer to change angle
        //*p=100;

        printf("Please enter target range: ");
        scanf("%f",&Sxx);
        printf("Please enter target height: ");
        scanf("%f",&Syy);
        printf("\n");

        p=&E;                   //*p is a pointer to determine error message in for loop

        for(U=110; U<=130; U+=5)
        {
            //40 degrees to 85 degrees
            for(z=0.69;z<=1.48;z+=0.01){



                Uy=U*sin(z);
                Ux=U*cos(z);
                Vx=Ux;
                t=Uy/g;
                Vy=Uy-g*t;
                Sx=Ux*t;
                Sy=Uy*t-0.5*g*t*t;
                zdeg=z*(180/M_PI);

                if(U==110)
                        a=0;
                    else if (U==115)
                        a=1;
                    else if (U==120)
                        a=2;
                    else if (U==125)
                        a=3;
                    else
                        a=4;




                if ((Sxx<Sx) && (Syy<Sy)){

                    *p=0;

                    printf("Muzzle Velocity(m/s)=%.2f\t Angle(deg)=%.2f\t Max Range(m) %.2f\t Max Height(m) %.2f\t\t Aug num %d\n",U,zdeg,Sx,Sy,a);
            }
                    else
                        *p=1;



            }


        }
    if (*p==1)
    printf("Obstacle cannot be cleared");





    exit(0);
}



