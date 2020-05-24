import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import javax.swing.*;

public class LoginPurchaseDetails {
	static HashMap<Integer, Long> hm = new HashMap<>();
	static ArrayList<Item> items = new ArrayList<>();
	String cid;
	JTextField tphn;
	
	public LoginPurchaseDetails() {
		JFrame frm1 = new JFrame();
		JButton btn = new JButton("Check");
		String name = JOptionPane.showInputDialog(null, "Enter Username : ", "");
		
		if(name.equalsIgnoreCase("admin")) {
			String pwd = JOptionPane.showInputDialog(null, "Enter Password : ", "");
			
			if(pwd.equals("admin")) {
				JLabel phno = new JLabel("Enter Phone Number : ");
				tphn = new JTextField(10);
				
				frm1.add(phno);
				frm1.add(tphn);
				frm1.add(btn);

				frm1.setVisible(true);
				frm1.setSize(300,300);
				frm1.setLayout(new FlowLayout());
				
				btn.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						int flag = 0;
						Set<Map.Entry<Integer, Long>> set1 = hm.entrySet();
						for(Map.Entry<Integer, Long> set2 : set1) {
							if(Long.parseLong(tphn.getText()) == set2.getValue()) {
								form(set2.getValue(),set2.getKey());
								flag = 1;
								break;
							}
						}
						if(flag == 0) {
							Long phno = Long.parseLong(tphn.getText());
							cid = JOptionPane.showInputDialog(null,"Enter Customer ID","input");
							form(phno,Integer.parseInt(cid));
							hm.put(Integer.parseInt(cid), phno);
						}
					}
				});
			} 
			else {
				JOptionPane.showMessageDialog(null, "Invalid Password", "Error", JOptionPane.ERROR_MESSAGE);
				new LoginPurchaseDetails();
			}
		} 
		else {
			JOptionPane.showMessageDialog(null, "Invalid Username", "Error", JOptionPane.ERROR_MESSAGE);
			new LoginPurchaseDetails();
		}
	}
	
	public void form(Long phno,int cid) {
		JFrame frm2 = new JFrame("Customer Details");
		JLabel idlab = new JLabel("User ID : ");
		JLabel phlab = new JLabel("Phone Number : ");
		JLabel itemIdLab = new JLabel("Enter Item ID");
		JLabel qlab = new JLabel("Enter Quantity : ");
		JLabel itemname = new JLabel("Item Name : ");
		JLabel itemprice = new JLabel("Item Price : ");
		
		JTextField idf = new JTextField(20);
		JTextField phf = new JTextField(20);
		JTextField itemid = new JTextField(20);
		JTextField quant = new JTextField(20);
		JTextField itname = new JTextField(20);
		JTextField itprice = new JTextField(20);
		JButton submit = new JButton("Submit");
		
		frm2.add(idlab); frm2.add(idf);
		idf.setText(String.valueOf(cid));
		idf.setEditable(false);
		
		frm2.add(phlab);frm2.add(phf);
		phf.setText(String.valueOf(phno));
		phf.setEditable(false);
		
		frm2.add(itemIdLab);frm2.add(itemid);
		
		frm2.add(qlab);frm2.add(quant);
		
		frm2.add(itemname);frm2.add(itname);
		itname.setEditable(false);
		
		frm2.add(itemprice);frm2.add(itprice);
		itprice.setEditable(false);
		
		frm2.add(submit);
		submit.addActionListener(new ActionListener() {
		
			@Override
			public void actionPerformed(ActionEvent evt) {
				int item = Integer.parseInt(itemid.getText());
				int q = Integer.parseInt(quant.getText());
				for(Item i: items) {
					if(i.ID == item) {
						itname.setText(i.name);
						double total = q*i.price;
						itprice.setText(String.valueOf(total));
						String discounts[] =  {"5","10","15"};
						int r = JOptionPane.showOptionDialog(null, "Select the discount percent", "Discount", 0, JOptionPane.INFORMATION_MESSAGE, null, discounts, discounts[0]);
						double totalCost = total-(int)(0.01*Integer.parseInt(discounts[r])*total);
						
						JOptionPane.showMessageDialog(null,"Total Price to be Paid : "+totalCost,"TotalCost",JOptionPane.INFORMATION_MESSAGE);
					}
				}
			}
		});
		frm2.setSize(500,500);
		frm2.setVisible(true);
		frm2.setLayout(new GridLayout(7,2));
	}
	
	public static void main(String[] args) {
		hm.put(1, 9087654321l);
		hm.put(2, 9876543210l);
		new LoginPurchaseDetails();
		
		items.add(new Item(1,"Bat",500.67));
		items.add(new Item(2,"Racquet",950.67));
		items.add(new Item(3,"Ball",200.20));
	}
}