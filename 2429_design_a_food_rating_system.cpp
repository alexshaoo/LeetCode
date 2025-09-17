class FoodRatings {
public:
  struct cmp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
      if (a.first == b.first) return a.second < b.second;
      return a.first > b.first;
    }
  };
  unordered_map<string, set<pair<int, string>, cmp>> cuisineFood;
  unordered_map<string, pair<int, string>> foodCuisine;
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = foods.size();
    for (int i = 0; i < n; ++i) {
      cuisineFood[cuisines[i]].insert({ratings[i], foods[i]});
      foodCuisine[foods[i]] = {ratings[i], cuisines[i]};
    }
  }
  
  void changeRating(string food, int newRating) {
    auto [oldRating, cuisine] = foodCuisine[food];
    cuisineFood[cuisine].erase({oldRating, food});
    cuisineFood[cuisine].insert({newRating, food});
    foodCuisine[food].first = newRating;
  }
  
  string highestRated(string cuisine) {
    return cuisineFood[cuisine].begin()->second;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */