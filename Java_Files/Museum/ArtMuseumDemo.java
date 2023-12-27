package Museum;

import java.util.*;

public class ArtMuseumDemo {
    public static void main(String[] args) {
        ArtMuseum_1 museum = new ArtMuseum_1();
        Scanner scanner = new Scanner(System.in);

        List<Painting_2> paintings = new ArrayList<>();

        while (true) {
            System.out.println("Выберите действие:");
            System.out.println("1. Добавить картину");
            System.out.println("2. Поиск картин по названию");
            System.out.println("3. Удалить картину");
            System.out.println("4. Сортировка картин по художнику");
            System.out.println("5. Вывести все картину в музее");
            System.out.println("0. Выход");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Очистка буфера

            switch (choice) {
                case 1:
                    System.out.println("Введите информацию о картине:");
                    System.out.print("Название: ");
                    String title = scanner.nextLine();
                    System.out.print("Художник: ");
                    String artist = scanner.nextLine();
                    System.out.print("Год создания: ");
                    int year = scanner.nextInt();
                    scanner.nextLine(); // Очистка буфера

                    paintings.add(new Painting_2(title, artist, year));
                    break;
                case 2:
                    System.out.print("Введите название для поиска: ");
                    String searchTitle = scanner.nextLine();
                    List<Painting_2> searchResult = new ArrayList<>();
                    for (Painting_2 painting : paintings) {
                        if (painting.getTitle().equalsIgnoreCase(searchTitle)) {
                            searchResult.add(painting);
                        }
                    }
                    System.out.println("Результат поиска по названию:");
                    for (Painting_2 painting : searchResult) {
                        System.out.println(painting);
                    }
                    break;
                case 3:
                    System.out.print("Введите название картину для удаления: ");
                    String removeTitle = scanner.nextLine();
                    Painting_2 paintingToRemove = null;
                    for (Painting_2 painting : paintings) {
                        if (painting.getTitle().equalsIgnoreCase(removeTitle)) {
                            paintingToRemove = painting;
                            break;
                        }
                    }
                    if (paintingToRemove != null) {
                        paintings.remove(paintingToRemove);
                        System.out.println("Картина успешно удалена.");
                    } else {
                        System.out.println("Картина не найдена.");
                    }
                    break;
                case 4:
                    Collections.sort(paintings, new Comparator<Painting_2>() {
                        @Override
                        public int compare(Painting_2 p1, Painting_2 p2) {
                            return p1.getArtist().compareToIgnoreCase(p2.getArtist());
                        }
                    });
                    System.out.println("Сортировка по художнику:");
                    for (Painting_2 painting : paintings) {
                        System.out.println(painting);
                    }
                    break;
                case 5:
                    System.out.println("Все картины в музее:");
                    for (Painting_2 painting : paintings) {
                        System.out.println(painting);
                    }
                    break;
                case 0:
                    System.out.println("Программа завершена.");
                    return;
                default:
                    System.out.println("Некорректный выбор. Попробуйте еще раз.");
                    break;
            }
        }
    }
}
