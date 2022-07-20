function Exemplo_Cores_1B(r, g, b)
    
    double r=0.0;  double g=0.0;  double b=0.0;
    double x=0.0;  double y=0.0;  double z=0.0;
    double L=0.0;  double a=0.0;  double bb=0.0;

    double r1=0.0; double g1=0.0; double b1=0.0;
    double r2=0.0; double g2=0.0; double b2=0.0;
    double rl=0.0; double gl=0.0; double bl=0.0;

    if ((r / 255) > 0.04045) 
       r1 = ((((r / 255) + 0.055) / 1.055) ^ 2.4);
    else 
       r1 = (r / 255) / 12.92;
    end
    if ((g / 255) > 0.04045)
       g1 = ((((g / 255) + 0.055) / 1.055) ^ 2.4);
    else
       g1 = (g / 255) / 12.92;
    end
    if ((b / 255) > 0.04045)
       b1 = ((((b / 255) + 0.055) / 1.055) ^ 2.4);
    else
       b1 = (b / 255) / 12.92;
    end

    x = r1 * 41.24 + g1 * 35.76 + b1 * 18.05;
    y = r1 * 21.26 + g1 * 71.52 + b1 * 7.22;
    z = r1 * 1.93  + g1 * 11.92 + b1 * 95.05;

    rl = x / 94.81;
    gl = y / 100.0;
    bl = z / 107.3;

    if (bl > 0.008856)
       r2 = (bl ^ 0.33333);
    else
       r2 = (7.787 * bl) + (16.0 / 116.0);
    end
    if (gl > 0.008856)
       g2 = (gl ^ 0.33333);
    else
       g2 = (7.787 * gl) + (16.0 / 116.0);
    end
    if (rl > 0.008856)
       b2 = (rl ^ 0.33333);
    else
       b2 = (7.787 * rl) + (16.0 / 116.0);
    end

    L = (116.0 * g2) - 16.0;
    a =  500.0 * (b2 - g2);
    bb=  200.0 * (g2 - r2);


    display(sprintf('    RGB -> R:%7.2f G:%7.2f B:%7.2f ', r, g, b));
    display(sprintf('CIE xyz -> x:%7.2f y:%7.2f z:%7.2f ', x, y, z));
    display(sprintf('CIE Lab -> L:%7.2f a:%7.2f b:%7.2f ', L, a, bb));
end