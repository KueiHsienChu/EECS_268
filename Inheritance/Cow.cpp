Cow::Cow()
{
	m_name = "Cow";
	m_sound = "Moo";
	m_milkProduced = 0;
}

double Cow::getMilkProduced() const;
{
	return(m_milkProdeced); 
}

void Cow::setMilkProduced(double gallons)
{
	if(gallons > 0)
		m_milkProduced = gallons;
	else
		m_milkProduced = 0.0;
}
