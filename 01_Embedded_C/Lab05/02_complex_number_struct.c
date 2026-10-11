#include <stdio.h>

struct Complex {
    double real;
    double img;
};

void clear_input_buffer(void);
double read_double(void);
struct Complex add_two_complex(struct Complex z1,struct Complex z2);
void print_complex(struct Complex z);
struct Complex multiply_two_complex(struct Complex z1,struct Complex z2);
int main(void) {
    struct Complex z1,z2;
    printf("Enter the real part for the first number : ");
    z1.real = read_double();
    printf("Enter the imaginary part for the first number : ");
    z1.img = read_double();
    printf("Enter the real part for the second number : ");
    z2.real = read_double();
    printf("Enter the imaginary part for the second number : ");
    z2.img = read_double();

    struct Complex result = add_two_complex(z1, z2);
    printf("z1 + z2 = ");
    print_complex(result);

    result = multiply_two_complex(z1, z2);
    printf("z1 x z2 = ");
    print_complex(result);
    return 0;
}

double read_double(void){
    double data;
    while(1){
        int ret = scanf("%lf", &data);
        clear_input_buffer();
        if(ret != 1){
            printf("Enter a number\n");
            continue;
        }
        return data;
    }   
}

void clear_input_buffer(void){
    int buf ;       // can't be char because on some compiler char is unsigned and EOF = -1 so it will never equal to each other
    while((buf = getchar())){
        if(buf == '\n' || buf == EOF){
            break;
        }
    }
}

struct Complex add_two_complex(struct Complex z1,struct Complex z2){
    struct Complex result;
    result.real = z1.real + z2.real;
    result.img = z1.img + z2.img;
    return result;
}

void print_complex(struct Complex z){
    if(z.img < 0.0){
        printf("%g - %gi\n", z.real, -1*z.img);
    }else {
        printf("%g + %gi\n", z.real, z.img);
    }
}


struct Complex multiply_two_complex(struct Complex z1,struct Complex z2){
    struct Complex result;
    result.real = (z1.real * z2.real) - (z1.img * z2.img);
    result.img = (z1.real * z2.img) + (z1.img * z2.real);
    return result;
}
