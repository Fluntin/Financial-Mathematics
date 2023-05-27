#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff {
public:
    PayOff() {}
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff() {}
private:
};

class PayOffCall : public PayOff {
public:
    PayOffCall(double Strike_) : Strike(Strike_) {}
    virtual double operator()(double Spot) const {
        return std::max(Spot - Strike, 0.0);
    }
    virtual ~PayOffCall() {}
private:
    double Strike;
};

class PayOffPut : public PayOff {
public:
    PayOffPut(double Strike_) : Strike(Strike_) {}
    virtual double operator()(double Spot) const {
        return std::max(Strike - Spot, 0.0);
    }
    virtual ~PayOffPut() {}
private:
    double Strike;
};

#endif
