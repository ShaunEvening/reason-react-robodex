type robot = {name: string, id: string};

module RobotCard = {
  include ReactRe.Component;
  let name = "robotCard";
  type props = {robot};
  let render {props} => {
    let imagePath = "https://robohash.org/" ^ props.robot.id ^ "?size=200x200";
    <div className="robot-card grow bg-light-blue br3 pa3 pb0 ma3 dib tc">
      <h2 className="ttc"> (ReactRe.stringToElement props.robot.name) </h2>
      <img role="presentation" src=imagePath />
    </div>
  };
};

include ReactRe.CreateComponent RobotCard;

let createElement ::robot => wrapProps {robot: robot};
