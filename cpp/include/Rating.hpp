#ifndef RATING_HPP
#define RATING_HPP

class Rating
{
    private:
        int userId;
        int movieId;
        double rating;
        long timestamp;

    public:
        Rating(int u, int m, double r, long t) : userId(u), movieId(m), rating(r), timestamp(t) {}
        
        int getUserId() const { return userId; }
        int getMovieId() const { return movieId; }
        double getRating() const { return rating; }
        long getTimestamp() const { return timestamp; }
};

#endif