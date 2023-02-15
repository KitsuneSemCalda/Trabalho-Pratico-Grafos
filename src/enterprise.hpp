class Customer{
  private:
    int id;
    int demand;
    int service_time;
    int arrival_time_lower_bound;
    int arrival_time_upper_bound;

  public:
    Customer(int id, int demand, int service_time, int arrival_time_lower_bound, int arrival_time_upper_bound){
      this->id = id;
      this->demand = demand;
      this->service_time = service_time;
      this->arrival_time_lower_bound = arrival_time_lower_bound;
      this->arrival_time_upper_bound = arrival_time_upper_bound;
    };
    
    ~Customer(){};

    int get_id() const{
      return this->id;
    };
    int get_demand() const{
      return this->demand;  
    };
    int get_service_time() const{
      return this->service_time;  
    };
    int get_arrival_time_lower_bound() const{
      return this->arrival_time_lower_bound;  
    };
    int get_arrival_time_upper_bound() const{
      return this->arrival_time_upper_bound;
    };

    void set_id(int id){
      this->id = id;
    };
    void set_demand(int demand){
      this->demand = demand;
    };
    void set_service_time(int service_time){
      this->service_time = service_time;
    };
    void set_arrival_time_lower_bound(int arrival_time_lower_bound){
      this->arrival_time_lower_bound = arrival_time_lower_bound;
    };
    void set_arrival_time_upper_bound(int arrival_time_upper_bound){
      this->arrival_time_upper_bound = arrival_time_upper_bound;  
    };
};

class Vehicle{
  private:
    int id;
    int capacity;
  public:
    int get_id() const{
      return this->id;  
    };
    int get_capacity() const{
      return this->capacity;
    };
    void set_id(int id){
      this->id = id;
    };
    void set_capacity(int capacity){
      this->capacity = capacity;  
    };
};

class Deposity{
  private:
    int id;
    int arrival_time_lower_bound;
    int arrival_time_upper_bound;

  public:
    int get_id() const{
        return this->id;  
    };
    int get_arrival_time_lower_bound() const{
        return this->arrival_time_lower_bound;
    };
    int get_arrival_time_upper_bound() const{
        return this->arrival_time_upper_bound;
    };
    void set_id(int id){
        this->id = id;  
    };
    void set_arrival_time_lower_bound(int arrival_time_lower_bound){
        this->arrival_time_lower_bound = arrival_time_lower_bound;
    };
    void set_arrival_time_upper_bound(int arrival_time_upper_bound){
        this->arrival_time_upper_bound = arrival_time_upper_bound;
    };
};
