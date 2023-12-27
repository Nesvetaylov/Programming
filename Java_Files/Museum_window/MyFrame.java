package Museum_window;

import javax.swing.*;

public class MyFrame extends JFrame {
    MyFrame() {
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        MyPanel panel = new MyPanel();
        add(panel);
        setVisible(true);
    }

}