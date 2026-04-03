from ultralytics import YOLO
def main():

    model = YOLO('yolo12n.pt')

    results = model.train(
        data = './Hand Gestures.v2i.yolov12/data.yaml',
        imgsz = 640,
        epochs = 60,
        device = 'cuda',
    )

if __name__ == '__main__':
    main()

