package Museum;

public class Painting_2 {
    private String title;
    private String artist;
    private int year;

    public Painting_2(String title, String artist, int year) {
        this.title = title;
        this.artist = artist;
        this.year = year;
    }

    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }

    public int getYear() {
        return year;
    }

    @Override
    public String toString() {
        return "Картина{" +
                "Название='" + title + '\'' +
                ", Художник='" + artist + '\'' +
                ", Год=" + year +
                '}';
    }
}