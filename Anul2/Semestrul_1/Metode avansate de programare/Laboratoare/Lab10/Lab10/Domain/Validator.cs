namespace Lab10.Domain;

public class Validator
{
    public void Validate(int year, int month, int day)
    {
        if (year < 1 || year > 9999)
        {
            throw new ArgumentOutOfRangeException("An invalid");
        }

        if (month < 1 || month > 12)
        {
            throw new ArgumentOutOfRangeException("Luna invalida");
        }

        int daysInMonth;
        switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysInMonth = 31;
                break;
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:
                if (IsLeapYear(year)) 
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
                break;
            default:
                throw new ArgumentOutOfRangeException("Luna invalida");
        }
        if (day < 1 || day > daysInMonth)
        {
            throw new ArgumentOutOfRangeException($"Ziua trebuie sa fine intre 1 si {daysInMonth} pentru luna data.");
        }
    }
    private bool IsLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}