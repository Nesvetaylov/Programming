package Museum_window;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ArtMuseum {
    private List<Painting> paintings;

    public ArtMuseum() {
        paintings = new ArrayList<>();
    }
    public ArtMuseum(List<Painting> a) {
        paintings = a;
    }
    public void addPainting(Painting painting) {
        paintings.add(painting);
    }

    public void removePainting(Painting painting) {
        paintings.remove(painting);
    }

    public void removePaintingByTitle(String title) {
        paintings.removeIf(painting -> painting.getTitle().equals(title));
    }

    public List<Painting> searchByTitle(String title) {
        List<Painting> result = new ArrayList<>();
        for (Painting painting : paintings) {
            if (painting.getTitle().equals(title)) {
                result.add(painting);
            }
        }
        return result;
    }

    public List<Painting> searchByArtist(String artist) {
        List<Painting> result = new ArrayList<>();
        for (Painting painting : paintings) {
            if (painting.getArtist().equals(artist)) {
                result.add(painting);
            }
        }
        return result;
    }

    public List<Painting> sortByTitle() {
        List<Painting> sortedList = new ArrayList<>(paintings);
        Collections.sort(sortedList, Comparator.comparing(Painting::getTitle));
        return sortedList;
    }

    public List<Painting> sortByArtist() {
        List<Painting> sortedList = new ArrayList<>(paintings);
        Collections.sort(sortedList, Comparator.comparing(Painting::getArtist));
        return sortedList;
    }

    public List<Painting> sortByYear() {
        List<Painting> sortedList = new ArrayList<>(paintings);
        Collections.sort(sortedList, Comparator.comparing(Painting::getYear));
        return sortedList;
    }

    public List<Painting> getPaintings() {
        return paintings;
    }

    public void addFirstObject(){
        paintings.add(new Painting("УтроНаСессии", "Подколзин", 2023));
        paintings.add(new Painting("ЗачетнаяНеделя", "Харченко", 2022));
        paintings.add(new Painting("ФантастическиеАлгоритмы", "Миков", 2021));
        paintings.add(new Painting("УвлекательныйМатанализ", "Александров", 2020));
        paintings.add(new Painting("ДифференциальноеПомешательство", "Ковтуненко", 2004));
        paintings.add(new Painting("ВПоискахФизрука", "Неуловимый", 1995));
    }


    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("Картины:\n");
        for (Painting m : paintings) {
            str.append(m.getTitle())
                    .append(", ")
                    .append(m.getArtist())
                    .append("(")
                    .append(m.getYear())
                    .append(")\n");
        }
        return str.toString();
    }
}