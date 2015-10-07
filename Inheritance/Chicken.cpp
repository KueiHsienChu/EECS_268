Chicken::Chicken()
{
	m_sounds = "Cluck";
	m_name = "Chicken";
	m_eggs = 0;
}

int Chicken::getEggs() const
{
	return(m_eggs);
}

void Chicken::setEggs(int eggs)
{
	m_eggs = eggs;
}


