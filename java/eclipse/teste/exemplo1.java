import javax.swing.*;        
import java.awt.FlowLayout;
import java.awt.event.*;

public class exemplo1 implements ActionListener {
	JButton b1, b2; 
	public void actionPerformed(ActionEvent e){
		if (e.getSource() == b1 )

						System.out.println("Submit button pressed");
				else
						 System.out.println("Cancel button pressed");
				
	}



    public void criar() {

        //Cria e configura a janela
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout( new FlowLayout() ); // configura o layout do frame


        //Cria e adiciona o label com "Hello World"
        JLabel label = new JLabel("Hello World");
        frame.getContentPane().add(label);
        b1 = new JButton("Submit");
        b2 = new JButton("Cancel");

b1.addActionListener(this);
b2.addActionListener(this);

        frame.getContentPane().add(b1);
        frame.getContentPane().add(b2);

        frame.pack();
        frame.setVisible(true);
    }
}

