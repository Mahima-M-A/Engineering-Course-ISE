import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;
import java.util.regex.Pattern;

import javax.swing.JButton;
import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.text.NumberFormatter;

public class StudentDetails implements ActionListener{
	JFrame f;
	JLabel l1, l2, l3, l4, l5, l51, l52, l53, l54, l55, l56, l57, l58, l6;
	JTextField t1, t2, t3, t4, t51, t52, t53, t54, t55, t56, t57, t58, t6;
	JTextArea ta1;
	JButton b1, b2;
	ArrayList<StudentDetailsCollection> list = new ArrayList<StudentDetailsCollection>();
	
	public StudentDetails() {
		f = new JFrame();
		l1 = new JLabel("Name");
		l2 = new JLabel("USN");
		l3 = new JLabel("Age");
		l4 = new JLabel("Address");
		l5 = new JLabel("SGPA");
		l51 = new JLabel("Semester 1");
		l52 = new JLabel("Semester 2");
		l53 = new JLabel("Semester 3");
		l54 = new JLabel("Semester 4");
		l55 = new JLabel("Semester 5");
		l56 = new JLabel("Semester 6");
		l57 = new JLabel("Semester 7");
		l58 = new JLabel("Semester 8");
		l6 = new JLabel("CGPA");
		
		t1 = new JTextField(20);
		t2 = new JTextField(10);
		
		NumberFormatter nf = new NumberFormatter();
		nf.setMinimum(new Float(0));
		nf.setMaximum(new Float(100));
		t3 = new JFormattedTextField(nf);
		t3.setColumns(10);
		t4 = new JTextField(20);
		t6 = new JTextField(10);
		t6.setEditable(false);

		nf = new NumberFormatter();
		nf.setMinimum(new Float(0));
		nf.setMaximum(new Float(10));
		
		t51 = new JFormattedTextField(nf);
		t51.setColumns(10);
		t52 = new JFormattedTextField(nf);
		t52.setColumns(10);
		t53 = new JFormattedTextField(nf);
		t53.setColumns(10);
		t54 = new JFormattedTextField(nf);
		t54.setColumns(10);
		t55 = new JFormattedTextField(nf);
		t55.setColumns(10);
		t56 = new JFormattedTextField(nf);
		t56.setColumns(10);
		t57 = new JFormattedTextField(nf);
		t57.setColumns(10);
		t58 = new JFormattedTextField(nf);
		t58.setColumns(10);
		
		ta1 = new JTextArea(20, 40);
		ta1.setEditable(false);
		
		b1 = new JButton("Compute");
		b2 = new JButton("Done");
		
		f.setLayout(new FlowLayout());
		f.add(l1);
		f.add(t1);
		f.add(l2);
		f.add(t2);
		f.add(l3);
		f.add(t3);
		f.add(l4);
		f.add(t4);
		f.add(l5);
		f.add(l51);
		f.add(t51);
		f.add(l52);
		f.add(t52);
		f.add(l53);
		f.add(t53);
		f.add(l54);
		f.add(t54);
		f.add(l55);
		f.add(t55);
		f.add(l56);
		f.add(t56);
		f.add(l57);
		f.add(t57);
		f.add(l58);
		f.add(t58);
		f.add(b1);
		f.add(b2);
		f.add(l6);
		f.add(t6);
		f.add(ta1);
		f.setVisible(true);
		f.setSize(600, 600);
		b1.addActionListener(this);
		b2.addActionListener(this);
	}
	
	public static void main(String[] args) {
		new StudentDetails();
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			String name = t1.getText();
			String usn = t2.getText();
			String address = t4.getText();
			
			if(name.equals("") || usn.equals("") || address.equals("")) {
				throw new EmptyFieldException();
			}
			else if(!Pattern.matches("1MS[0-9][0-9]IS[0-9][0-9][0-9]", usn)) {
				throw new USNException();
			}
			
			int age = Integer.parseInt(t3.getText());
			float s1 = Float.parseFloat(t51.getText());
			float s2 = Float.parseFloat(t52.getText());
			float s3 = Float.parseFloat(t53.getText());
			float s4 = Float.parseFloat(t54.getText());
			float s5 = Float.parseFloat(t55.getText());
			float s6 = Float.parseFloat(t56.getText());
			float s7 = Float.parseFloat(t57.getText());
			float s8 = Float.parseFloat(t58.getText());
			float cgpa = (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8)/8;
			
			if(e.getSource() == b1) {
				t6.setText(String.valueOf(cgpa));
			}
			if(e.getSource() == b2) {
				list.add(new StudentDetailsCollection(name, usn, age, address, s1, s2, s3, s4, s5, s6, s7, s8, cgpa));
				ta1.setText("");
				String details = "";
				for(StudentDetailsCollection sd : list) {
					details += sd.toString();
				}
				ta1.setText(details);
				reset();
			}
		}
		catch(USNException ex) {
			JOptionPane.showMessageDialog(f, "Invalid USN", "Error", JOptionPane.ERROR_MESSAGE);
			t2.setText("");
		}
		catch(EmptyFieldException ex) {
			JOptionPane.showMessageDialog(f, "All fields are required", "Error", JOptionPane.ERROR_MESSAGE);
		}
		catch(NumberFormatException ex) {
			JOptionPane.showMessageDialog(f, "Invalid number", "Error", JOptionPane.ERROR_MESSAGE);
		}
	}
	public void reset() {
		t1.setText("");
		t2.setText("");
		t3.setText("");
		t4.setText("");
		t51.setText("");
		t52.setText("");
		t53.setText("");
		t54.setText("");
		t55.setText("");
		t56.setText("");
		t57.setText("");
		t58.setText("");
		t6.setText("");
	}
}
