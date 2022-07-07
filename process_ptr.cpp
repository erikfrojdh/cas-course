
double *process(short *rf, int nr, int nc, double *pd, double *cal) {
    double *data = new double[nr * nc];
    for (int i = 0; i < nr * nc; ++i) {
        int g = rf[i] >> 14;
        if (g == 3)
            g = 2;
        data[i] = ((rf[i] & 0x3FFF) - pd[i]) / cal[i + (nr * nc * g)];
    }
    return data;
}
