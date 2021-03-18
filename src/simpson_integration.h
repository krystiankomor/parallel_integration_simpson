class SimpsonIntegration {
    public:
        SimpsonIntegration(double a, double b, double c, double x1, double x2, int n, int p);
        void count();
        double getResult();

    private:
        double a, b, c, x1, x2, ts, tp, dx, s, st, result;
        int n;
        double integrationFunction(double number);
        double countX(double x, int i, double dx);
        double countS(double dx);
        double countSt(double dx);
};