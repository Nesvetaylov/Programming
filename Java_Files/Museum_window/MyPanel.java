package Museum_window;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyPanel extends JPanel {
    JLabel l0, l1, l2, l3, l4, l5, l6, l7, p1, p2, p3, p4;
    JTextField f1, f2, f3, f4, f5;
    JTextArea f6;
    JButton button1, button2, button3, button4, button5, button6;

    ArtMuseum mus;



    MyPanel() {
        mus = new ArtMuseum();
        mus.addFirstObject();

        setLayout(new GridLayout(1, 2));

        JPanel leftPanel = new JPanel(new GridLayout(0, 1));
        JPanel rightPanel = new JPanel(new GridLayout(0, 1));


        leftPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        rightPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        p1 = new JLabel(" ");
        leftPanel.add(p1);

        l0 = new JLabel("ДОБАВЛЕНИЕ КАРТИНЫ");
        leftPanel.add(l0);

        p2 = new JLabel(" ");
        leftPanel.add(p2);


        l1 = new JLabel("Назание:");
        leftPanel.add(l1);
        f1 = new JTextField();
        f1.setColumns(10);
        leftPanel.add(f1);

        l2 = new JLabel("Художник:");
        leftPanel.add(l2);
        f2 = new JTextField();
        f2.setColumns(10);
        leftPanel.add(f2);

        l3 = new JLabel("Год:");
        leftPanel.add(l3);
        f3 = new JTextField();
        f3.setColumns(10);
        leftPanel.add(f3);

        p3 = new JLabel(" ");
        leftPanel.add(p3);

        button1 = new JButton("ДОБАВИТЬ");
        MyListener m = new MyListener(mus);
        button1.addActionListener(m);
        leftPanel.add(button1);

        p4 = new JLabel(" ");
        leftPanel.add(p4);

        l4 = new JLabel("УДАЛЕНИЕ ОБЪЕКТА ПО НАЗВАНИЮ");
        rightPanel.add(l4);

        f4 = new JTextField();
        f4.setColumns(10);
        rightPanel.add(f4);

        button6 = new JButton("УДАЛЕНИЕ");
        MyListener1 m1 = new MyListener1(mus);
        button6.addActionListener(m1);
        rightPanel.add(button6);



        l5 = new JLabel("ПОИСК ОБЪЕКТА ПО НАЗВАНИЮ");
        rightPanel.add(l5);

        f5 = new JTextField();
        f5.setColumns(10);
        rightPanel.add(f5);

        button2 = new JButton("ПОИСК");
        MyListener2 m2 = new MyListener2(mus);
        button2.addActionListener(m2);
        rightPanel.add(button2);





        l6 = new JLabel("СОРТИРОВКИ");
        rightPanel.add(l6);

        button3 = new JButton("ПО НАЗВАНИЮ");
        MyListener3 m3 = new MyListener3(mus);
        button3.addActionListener(m3);
        rightPanel.add(button3);

        button4 = new JButton("ПО ХУДОЖНИКУ");
        MyListener4 m4 = new MyListener4(mus);
        button4.addActionListener(m4);
        rightPanel.add(button4);

        button5 = new JButton("ПО ГОДУ");
        MyListener5 m5 = new MyListener5(mus);
        button5.addActionListener(m5);
        rightPanel.add(button5);



        l7 = new JLabel("ОКНО ВЫВОДА");
        rightPanel.add(l7);

        f6 = new JTextArea();
        f6.setColumns(10);
        f6.setRows(15);
        JScrollPane scrollPane = new JScrollPane(f6); // Add a scroll pane for text area
        rightPanel.add(scrollPane); // Add the scroll pane containing the text area

        // Set the preferred size of the JTextArea
        Dimension dim = new Dimension(200, 300); // Change dimensions as needed
        scrollPane.setPreferredSize(dim);

        add(leftPanel); // Adding left panel to the main panel
        add(rightPanel); // Adding right panel to the main panel
    }

    class MyListener implements ActionListener
    {
        ArtMuseum mus;

        MyListener(ArtMuseum mus){
            this.mus=mus;
        }

        public void actionPerformed(ActionEvent e) {

            String title = f1.getText();
            String artist = f2.getText();
            int year = Integer.parseInt(f3.getText());


            Painting newObject = new Painting(title, artist, year);
            mus.addPainting(newObject);

            f6.setText(mus.toString());
        }
    }

    class MyListener1 implements ActionListener
    {
        ArtMuseum mus;

        MyListener1(ArtMuseum mus){
            this.mus=mus;
        }

        public void actionPerformed(ActionEvent e) {
            String title = f5.getText();
            mus.removePaintingByTitle(title);
            f6.setText(mus.toString());
        }
    }


    class MyListener2 implements ActionListener
    {
        ArtMuseum mus;

        MyListener2(ArtMuseum mus){
            this.mus=mus;
        }

        public void actionPerformed(ActionEvent e) {
            String title = f5.getText();
            String str= mus.searchByTitle(title).toString();
            f6.setText(str);
        }
    }

    class MyListener3 implements ActionListener
    {
        ArtMuseum mus;

        MyListener3(ArtMuseum mus){
            this.mus=mus;
        }

        public void actionPerformed(ActionEvent e) {
            ArtMuseum SortMus = new ArtMuseum(mus.sortByTitle());
            f6.setText(SortMus.toString());
        }
    }

    class MyListener4 implements ActionListener
    {
        ArtMuseum mus;

        MyListener4(ArtMuseum mus){
            this.mus=mus;
        }

        public void actionPerformed(ActionEvent e) {
            ArtMuseum SortMus = new ArtMuseum(mus.sortByArtist());
            f6.setText(SortMus.toString());
        }
    }

    class MyListener5 implements ActionListener
    {
        ArtMuseum mus;

        MyListener5(ArtMuseum mus){
            this.mus=mus;
        }

        public void actionPerformed(ActionEvent e) {
            ArtMuseum SortMus = new ArtMuseum(mus.sortByYear());
            f6.setText(SortMus.toString());
        }
    }

}
