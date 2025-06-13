public class Rating {
    private int userId;
    private int movieId;
    private double rating;
    private long timestamp;

    public Rating(int userId, int movieId, double rating, long timestamp) {
        this.userId = userId;
        this.movieId = movieId;
        this.rating = rating;
        this.timestamp = timestamp;
    }

    public int getUserId() { return userId; }
    public int getMovieId() { return movieId; }
    public double getRating() { return rating; }
    public long getTimestamp() { return timestamp; }
}