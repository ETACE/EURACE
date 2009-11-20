import java.util.ArrayList;

/* bad bad programming */
/* no time to be good .... */
public class AgentList {
    
    public ArrayList<Agent> list;
    public int width;
    public int height;

    public AgentList (int width, int height) 
    {
        list = new ArrayList<Agent>();
        this.width = width;
        this.height = height;
    }

    public void addAgent(int id, float x, float y)
    {
        list.add(new Agent(id, x, y));
    }
}
