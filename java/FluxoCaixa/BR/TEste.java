package BR;

import java.util.List;
import BR.pais;

import net.sf.hibernate.Session;
import net.sf.hibernate.SessionFactory;
import net.sf.hibernate.Transaction;
import net.sf.hibernate.cfg.Configuration;

public class TEste {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Transaction trans = null;
		try {
			// Usando pooll de conex�o do Hibernate.cfg.xml e , mais elegante
			Configuration cfg = new Configuration();
			cfg.configure();

			// Define o contexto Hibernate - refer�ncia a conex�o
			SessionFactory factory = cfg.buildSessionFactory();
			Session session = factory.openSession();

			System.out.println("Conex�o Ok");

			session.flush();
			session.close();

		} catch (Exception e) {
			try {
				e.printStackTrace();
				trans.rollback();
			} catch (Exception ex) {
				ex.printStackTrace();
			}

		}
	}
}
