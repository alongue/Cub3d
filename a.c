#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct                        s_point
{
    int        x;
    int        y;
};
typedef struct s_point        t_point;

struct                        s_segment
{
    bool    exist;
    t_point    a;
    t_point    b;
    double    coeff;
    double    intercept;
};
typedef struct s_segment    t_segment;


int    ft_swap(void **a, void **b)
{
    void    *c;

    if (!a || !b)
        return (0);
    c = *b;
    *b = *a;
    *a = c;
    return (1);
}


int        get_extremity(t_segment segment, t_point *first, t_point *end)
{
    *first = dup_point(segment.a);
    *end = dup_point(segment.b); //tjrs les cas d'erreurs en mode overflow a gerer
    return (1);
}

int        main()
{
    t_point        a;
    t_point        b; //mettre les points en float a mon avis
    t_point        *acop;
    t_point        *bcop;
    t_segment    s;

    s.a.x = 10;
    s.a.y = 20;
    s.b.x = 30;
    s.b.y = 40;
    get_extremity(s, &a, &b);
    printf("a.y = %d\tet\ta.x =%d\nb.y = %d\tet\tb.x = %d\n", a.y, a.x, b.y, b.x);
    acop = &a;
    bcop = &b;
    if (a.y < b.y)
    {
        printf("je suis rentre\n");
        ft_swap((void *)&acop, (void *)&bcop);
		a = *acop;
		b = *bcop;

    }
    printf("a.y = %d\tet\ta.x =%d\nb.y = %d\tet\tb.x = %d\n", a.y, a.x, b.y, b.x);
}
