using namespace std;
#include <iostream>
#include <cmath>
#include <vector>

const int DIMENSION = 2;
const int MAX_DELAY_UNIT = 100000;

class state_system{
public:
    double _in;
    double _out;
    vector<double> x_d;
    vector<double> x;
    vector<vector<double>> a;
    vector<double> b;
    vector<double> c;
    double _t;
    vector<vector<int>> flag_a;
    vector<int> flag_b;
    vector<int> flag_c;
    double dev_min;
    vector<double> mudajikan_array;
    int array_write_position;
    int array_read_position;
    int delay_num;
    int dimension_size = DIMENSION;
    int elem_base = 300;
    int flag;

    state_system();
    void delay_array_init(int delay_num);
    void system_init(void);
    void system(void);
    void solve_delay_time(size_t max_delay ,vector<double>& _in, vector<double>& _out);

};
state_system::state_system(){
    x_d.resize(DIMENSION);
    x.resize(DIMENSION);
    a.resize(DIMENSION);
    for(size_t i = 0; i < DIMENSION;i++){
        a[i].resize(DIMENSION);
    }
    b.resize(DIMENSION);
    c.resize(DIMENSION);
    flag_a.resize(DIMENSION);
    for(size_t i = 0; i < DIMENSION;i++){
        flag_a[i].resize(DIMENSION);
    }
    flag_b.resize(DIMENSION);
    flag_c.resize(DIMENSION);
}

void state_system::delay_array_init(int delay_num){
    this->delay_num = delay_num;
    this->array_read_position = 0;
    this->array_write_position = this->delay_num;
}
void state_system::system_init(void){
    int i;
    this->_in = 0.0;
    this->_out = 0.0;
    for(i = 0;i < DIMENSION; i++){
        this->x_d[i] = 0.0;
    }

    for(i = 0;i < DIMENSION; i++){
        this->x[i] = 0.0;
    }
}
void state_system::system(){
    int i;
    int j;

    for(i = 0;i < DIMENSION;i++){
        this->x_d[i]=0.0;
        for(j = 0;j < DIMENSION;j++){
            this->x_d[i] += this->x[j] * this->a[i][j];
        }
        this->x_d[i] += this->_in * this->b[i];
    }
    for(i = 0;i < DIMENSION;i++){
        this->x[i] += this->x_d[i] * this->_t;
    }

    this->mudajikan_array[this->array_write_position] = 0.0;
    for(size_t i = 0; i < DIMENSION; i++){
        this->mudajikan_array[this->array_write_position] += this->x[i]*this->c[i];
    }
    this->_out=this->mudajikan_array[this->array_read_position];

    if(this->array_write_position >= 100000-1){
        this->array_write_position = 0;
    }
    else {
        this->array_write_position += 1;
    }
    if(this->array_read_position >= 100000-1){
        this->array_read_position = 0;
    }
    else {
        this->array_read_position += 1;
    }
}

void state_system::solve_delay_time(size_t max_delay,vector<double>& _in,vector<double>& _out){
    size_t i,j;
    double sum;
    double t;
    size_t elem;
    double final_value = 0.0;
    double min_coeff = 0.0;
    double sum_after = 0.0;
    double hyp = 1e-3;
    vector<double> dydt(0.0,DIMENSION);

    for(size_t i = 0; i < DIMENSION; i++){
        final_value = 0.0;

        this->system_init();
        this->delay_array_init(this->delay_num);
        sum = 0.0;
        t = 0.0;
        elem = this->elem_base;
        while(elem > 0){
            this->_in=_in[this->elem_base-elem];
            this->system();
            sum += pow(_out[this->elem_base-elem]-this->_out,2);
            t += this->_t;
            elem -= 1;
        }
        this->dev_min = sum;
        this->delay_num += 1;
        this->system_init();
        this->delay_array_init(this->delay_num);
        sum_after = 0.0;
        t = 0.0;
        elem=this->elem_base;
        while(elem > 0){
            this->_in=_in[this->elem_base-elem];
            this->system();
            sum_after += pow(_out[this->elem_base-elem]-this->_out,2);
            t += this->_t;
            elem -= 1;
        }
        this->delay_num -= 1;

        this->delay_num = (size_t) (((double)this->delay_num)-hyp*(sum_after-sum));

        if(this->delay_num >= 9999){
            this->delay_num = 9999;
        }
    }
    
}

int main(int argc, char **argv){
    state_system solver;
    cout << "hello" << endl;
    return 0;    
}