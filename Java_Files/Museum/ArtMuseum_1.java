package Museum;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ArtMuseum_1 {
    private List<Painting_2> paintings;

    public ArtMuseum_1() {
        paintings = new ArrayList<>();
    }

    public void addPainting(Painting_2 painting) {
        paintings.add(painting);
    }

    public void removePainting(Painting_2 painting) {
        paintings.remove(painting);
    }

    public void removePaintingByTitle(String title) {
        paintings.removeIf(painting -> painting.getTitle().equals(title));
    }

    public List<Painting_2> searchByTitle(String title) {
        List<Painting_2> result = new ArrayList<>();
        for (Painting_2 painting : paintings) {
            if (painting.getTitle().equals(title)) {
                result.add(painting);
            }
        }
        return result;
    }

    public List<Painting_2> searchByArtist(String artist) {
        List<Painting_2> result = new ArrayList<>();
        for (Painting_2 painting : paintings) {
            if (painting.getArtist().equals(artist)) {
                result.add(painting);
            }
        }
        return result;
    }

    public List<Painting_2> sortByTitle() {
        List<Painting_2> sortedList = new ArrayList<>(paintings);
        Collections.sort(sortedList, Comparator.comparing(Painting_2::getTitle));
        return sortedList;
    }

    public List<Painting_2> sortByArtist() {
        List<Painting_2> sortedList = new ArrayList<>(paintings);
        Collections.sort(sortedList, Comparator.comparing(Painting_2::getArtist));
        return sortedList;
    }

    public List<Painting_2> sortByYear() {
        List<Painting_2> sortedList = new ArrayList<>(paintings);
        Collections.sort(sortedList, Comparator.comparing(Painting_2::getYear));
        return sortedList;
    }

    public List<Painting_2> getPaintings() {
        return paintings;
    }
}